#! /usr/bin/env python3
"""Run the compiler, followed by CMake, make, make test - check it all works out"""
import argparse
import os
import shutil
import subprocess
import sys
from run_compiler import run_compiler, TestFailure
from try_build import try_build, CMakeFailure, MakeFailure, find_exceptions_cmake, find_rubicon_cmake

def copytree(src, dst, symlinks=False):
    names = os.listdir(src)
    os.makedirs(dst, exist_ok=True)
    errors = []
    for name in names:
        srcname = os.path.join(src, name)
        dstname = os.path.join(dst, name)
        try:
            if symlinks and os.path.islink(srcname):
                linkto = os.readlink(srcname)
                os.symlink(linkto, dstname)
            elif os.path.isdir(srcname):
                copytree(srcname, dstname, symlinks)
            else:
                shutil.copy2(srcname, dstname)
        except OSError as why:
            errors.append((srcname, dstname, str(why)))
        # catch the Error from the recursive copytree so that we can
        # continue with other files
        except Error as err:
            errors.extend(err.args[0])
    try:
        shutil.copystat(src, dst)
    except OSError as why:
        # can't copy file access times on Windows
        if why.winerror is None:
            errors.extend((src, dst, str(why)))
    if errors:
        raise Error(errors)

def setup_testcase(source_directory, testcase_directory):
    copytree(source_directory, testcase_directory)
    build_directory = testcase_directory + "/.build"
    os.makedirs(build_directory, exist_ok=True)

def build_testcase(testcase_directory, stage):
    build_directory = testcase_directory + "/.build"
    cwd = os.getcwd()
    try:
        if stage:
            exceptions_cmake = find_exceptions_cmake(stage)
            rubicon_cmake = find_rubicon_cmake(stage)
            stage_arguments = ['-Dexceptions_DIR=' + os.path.dirname(exceptions_cmake), '-Drubicon_DIR=' + os.path.dirname(rubicon_cmake)]
        else:
            stage_arguments = []
        os.chdir(build_directory)
        with subprocess.Popen(['cmake'] + stage_arguments + ['..'], stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
            proc.wait()
            if proc.returncode != 0:
                raise CMakeFailure("Failed to run CMake in " + build_directory)
        with subprocess.Popen(['make'], stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
            proc.wait()
            if proc.returncode != 0:
                raise MakeFailure("Failed to run Make in " + build_directory)
    finally:
        os.chdir(cwd)

def run_testcase(testcase_directory):
    build_directory = testcase_directory + "/.build"
    cwd = os.getcwd()
    try:
        os.chdir(build_directory)
        with subprocess.Popen(['make', 'test'], stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
            proc.wait()
            if proc.returncode != 0:
                raise MakeFailure("Failed to run Make test in " + build_directory)
    finally:
        os.chdir(cwd)

def try_testcase(filename, asn1c, module, source_directory, clean, build_only, extra_args, stage):
    cwd = os.getcwd()
    retval = 0
    try:
        print("Running asn1c... ", end='', flush=True)
        compile_result = run_compiler(asn1c, filename, module, extra_args)
        if compile_result['return-code'] == 0:
            print("OK")
            print("Building generated code (stand-alone)... ", end='', flush=True)
            try_build(compile_result['output-directory'], clean, stage)
            print("OK")
            if source_directory:
                os.chdir(cwd)
                print("Preparing the test case... ", end='', flush=True)
                setup_testcase(source_directory, os.path.abspath(compile_result['output-directory'] + "/.."))
                print("OK")
                print("Building the test case... ", end='', flush=True)
                build_testcase(os.path.abspath(compile_result['output-directory'] + "/.."), stage)
                print("OK")
                if not build_only:
                    print("Running the test case... ", end='', flush=True)
                    run_testcase(os.path.abspath(compile_result['output-directory'] + "/.."))
                    print("OK")
        else:
            print("asn1c returned an error")
            retval = 1
    except TestFailure as error:
        print(error)
        retval = 1
    finally:
        os.chdir(cwd)
    return retval

def main(argv):
    """main function for this module"""
    if '--' in argv:
        args_to_parse = argv[1:argv.index('--')]
        args_to_not_parse = argv[argv.index('--') + 1:]
    else:
        args_to_parse = argv[1:]
        args_to_not_parse = []
    parser = argparse.ArgumentParser(description="Run asn1c and check the results")
    parser.add_argument("filename", help=".asn file to parse")
    parser.add_argument("-C", "--clean", help="clean before building asn1c output", action='store_true')
    parser.add_argument("-b", "--build-only", help="build-only test", action='store_true')
    parser.add_argument("-c", "--asn1c", help="path to asn1c", default="./asn1c")
    parser.add_argument("-d", "--source-directory", help="source directory to copy into the generated files")
    parser.add_argument("-m", "--module", help="expected module name")
    parser.add_argument("-s", "--stage", help="staging directory")
    args = parser.parse_args(args_to_parse)
    stage = os.path.abspath(args.stage) if args.stage else None
    return(try_testcase(args.filename, args.asn1c, args.module, args.source_directory, args.clean, args.build_only, args_to_not_parse, stage))

if __name__ == "__main__":
    exit(main(sys.argv))

