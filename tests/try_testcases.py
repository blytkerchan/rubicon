#! /usr/bin/env python3
"""read a given CSV file and run the tests prescribed"""
import argparse
import csv
import os
import sys
from run_compiler import TestFailure
from try_testcase import try_testcase

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
    parser.add_argument("filename", help=".csv file to parse")
    parser.add_argument("-c", "--asn1c", help="path to asn1c", default="./asn1c")
    parser.add_argument("-k", "--keep-going", help="keep going if one of the tests fails", action='store_true')
    parser.add_argument("-s", "--stage", help="staging directory")
    args = parser.parse_args(args_to_parse)
    stage = os.path.abspath(args.stage) if args.stage else None
    try:
        with open(args.filename, newline='') as csvfile:
            reader = csv.DictReader(csvfile, delimiter=',')
            count = 0
            for row in reader:
                count = count + 1
                if row['skip'] == "True":
                    print("Skipping test {}".format(count))
                    continue
                print("Running test {}".format(count))
                dir_prefix = os.path.dirname(args.filename) + "/"
                this_test_result = try_testcase(dir_prefix + row['asn1-file'], args.asn1c, row['module'], dir_prefix + row['directory'] if row['directory'] else None, True if row['clean'] == 'True' else False, True if row['build-only'] == 'True' else False, args_to_not_parse, stage)
                if row['expect-fail'] == "True":
                    if this_test_result != 0:
                        print("SUCCESS: expected fail for test {}".format(count))
                        this_test_result = 1
                    else:
                        print("FAIL: unexpected success for test {}".format(count))
                        this_test_result = 0
                else:
                    if this_test_result != 0:
                        print("FAIL: test {}".format(count))
                    else:
                        print("SUCCESS")
                retval |= this_test_result
                if retval != 0 and not args.keep_going:
                    break
    except TestFailure as error:
        print(error)
        retval = 1
    finally:
        os.chdir(cwd)
    return retval

if __name__ == "__main__":
    exit(main(sys.argv))


