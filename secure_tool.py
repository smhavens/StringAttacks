# Tool to give corrections for weak coding.

# FIRST OPEN C FILE AND FIND BAD PRINTS
import sys
from enum import Enum


class error_type(Enum):
    PRINT = 1
    STACK = 2
    HEAP = 3
    INTEGER = 4
    DANGLING = 5


def print_correct(file):
    print("ATTEMPTING TO FIND PRINT ERRORS.")
    with open(file) as source:
        for line in source:
            print(line)
            if ('printf(' in line) and ('printf("' not in line) and ("printf('" not in line):
                print("ERROR")


def main():
    
    print ('argument list', sys.argv)
    file = sys.argv[1]
    print ("Now checking file {}".format(file))

    error_array_dict = []
    print_correct(file)


if __name__ == "__main__":
    main()