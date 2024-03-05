// Main file with poorly implemented code leaving room for attacks on the OS.
// Included attacks:
// poor string formatting
// stack and heap buffer overflows
// integer vulnerabilities
// and finally dangling pointers.

#include <stdio.h>


int main(int argc, char** argv) {

    //Poor formatting, user can insert commands.
    print(argv[1]);
}