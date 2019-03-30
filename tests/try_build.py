#! /usr/bin/env python3
"""Run the compiler, followed by CMake, make - check it all works out"""
import argparse
import os
from pathlib import Path
import shutil
import subprocess
import sys
from run_compiler import run_compiler, TestFailure

class CMakeFailure(TestFailure):
    pass
class MakeFailure(TestFailure):
    pass

def try_build(output_directory, clean):
    build_directory = output_directory + "/.build"
    if clean:
        build_dir = Path(build_directory)
        if build_dir.exists():
            shutil.rmtree(build_directory)
    os.makedirs(build_directory, exist_ok=True)
    os.chdir(build_directory)
    with subprocess.Popen(['cmake', '..'], stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
        proc.wait()
        if proc.returncode != 0:
            raise CMakeFailure("Failed to run CMake in " + build_directory)
    with subprocess.Popen(['make'], stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
        proc.wait()
        if proc.returncode != 0:
            raise CMakeFailure("Failed to run Make in " + build_directory)

def main(argv):
    """main function for this module"""
    cwd = os.getcwd()
    retval = 0
    if '--' in argv:
        args_to_parse = argv[1:argv.index('--')]
        args_to_not_parse = argv[argv.index('--') + 1:]
    else:
        args_to_parse = argv[1:]
        args_to_not_parse = []
    parser = argparse.ArgumentParser(description="Run asn1c and check the results")
    parser.add_argument("filename", help=".asn file to parse")
    parser.add_argument("-c", "--asn1c", help="path to asn1c", default="./asn1c")
    parser.add_argument("-m", "--module", help="expected module name")
    parser.add_argument("-C", "--clean", help="clean before building asn1c output", action='store_true')
    args = parser.parse_args(args_to_parse)
    try:
        print("Running asn1c... ", end='', flush=True)
        compile_result = run_compiler(args.asn1c, args.filename, args.module, args_to_not_parse)
        if compile_result['return-code'] == 0:
            print("OK")
            print("Building generated code (stand-alone)... ", end='', flush=True)
            try_build(compile_result['output-directory'], args.clean)
            print("OK")
        else:
            print("asn1c returned an error")
    except TestFailure as error:
        print(error)
        retval = 1
    finally:
        os.chdir(cwd)
    return retval

if __name__ == "__main__":
    exit(main(sys.argv))

