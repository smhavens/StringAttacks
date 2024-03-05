// Main file with poorly implemented code leaving room for attacks on the OS.
// Included attacks:
// poor string formatting
// stack and heap buffer overflows
// integer vulnerabilities
// and finally dangling pointers.

#include <stdio.h>
#include "main.h"

#define BUFSIZE 256

int main(int argc, char** argv) {

    // Poor formatting, user can insert commands.
    print(argv[1]);

    // Stack Buffer Overflow
    stack_weakness(argv[1]);

    // Heap Buffer Overflow
    heap_weakness();

    // Integer Vulnerabilities
    integer_weakness();

    // Dangling Pointers
    dangling_pointer();
}

// Using examples from https://cwe.mitre.org/data/definitions/121.html
int stack_weakness(char* vulnerability) {
    char buf[BUFSIZE];
    strcpy(buf, vulnerability);
    print(buf);
    return 0;
}

int heap_weakness() {
    return 0;
}

int integer_weakness() {
    return 0;
}

int dangling_pointer() {
    return 0;
}