#! /usr/bin/env python3
"""Run the asn1c compiler and check the output"""
import argparse
import re
import subprocess
import sys

class TestFailure(Exception):
    """Base class for run-time errors in this module"""
    pass
class ModuleNameNotFound(TestFailure):
    """Thrown when the module name is not found in the asn1c output"""
    pass
class ModuleNameMismatch(TestFailure):
    """Thrown when the module name found in the asn1c output doesn't match the one expected"""
    pass
class OutputDirectoryNotFound(TestFailure):
    """Thrown when the output directory was not found in the asn1c output"""
    pass

def check_module_name(stderr_lines, expected_module_name):
    """Check the module name in the stderr output of asn1c"""
    regex = re.compile('Module name: (.*)')
    module_names = [regex.match(l) for l in stderr_lines if regex.match(l)]
    if not module_names:
        msg = "No module name found. Expected {}".format(expected_module_name)
        raise ModuleNameNotFound(msg)
    found_module_name = module_names[0].group(1)
    if found_module_name != expected_module_name:
        msg = "Module name mis-match. Expected {0}, got {1}".format(expected_module_name, found_module_name)
        raise ModuleNameMismatch(msg)

def run_compiler(asn1c_path, input_filename, expected_module_name, extra_arguments):
    """Run the compiler at the given path, with the given arguments and
    expecting the given module name"""
    retval = dict()
    popen_arguments = [asn1c_path, input_filename] + extra_arguments
    with subprocess.Popen(popen_arguments, stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
        proc.wait()
        stderr_lines = [x.decode('utf-8') for x in proc.stderr.readlines()]
        stdout_lines = [x.decode('utf-8') for x in proc.stdout.readlines()]
        if expected_module_name:
            check_module_name(stderr_lines, expected_module_name)
            retval['module-name'] = expected_module_name
        regex = re.compile('Using output directory (.*)')
        output_directories = [regex.match(l) for l in stdout_lines if regex.match(l)]
        if not output_directories:
            raise OutputDirectoryNotFound("No output directory found in compiler output")
        retval['output-directory'] = output_directories[0].group(1)
        retval['return-code'] = proc.returncode
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
    parser.add_argument("-c", "--asn1c", help="path to asn1c", default="./asn1c")
    parser.add_argument("-m", "--module", help="expected module name")
    args = parser.parse_args(args_to_parse)
    try:
        print("Running asn1c... ", end='', flush=True)
        result = run_compiler(args.asn1c, args.filename, args.module, args_to_not_parse)
        if result['return-code'] != 0:
            print("Compiler returned an error")
            exit(1)
        else:
            print("OK")
    except TestFailure as error:
        print(error)
        exit(1)

if __name__ == "__main__":
    main(sys.argv)
