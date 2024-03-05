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

    char option = argv[1];

    switch(option){
        case 'p':
            // Poor formatting, user can insert commands.
            print_weakness(argv[2]);
            break;

        case 's':
            // Stack Buffer Overflow
            stack_weakness(argv[2]);
            break;

        case 'h':
            // Heap Buffer Overflow
            heap_weakness(argv[2]);
            break;

        case 'i':
            // Integer Vulnerabilities
            integer_weakness(argv[2], argv[3]);
            break;

        case 'd':
            // Dangling Pointers
            dangling_pointer();
            break;
        default:
            printf("have a nice day!");
    }
    
}

void print_weakness(char* vulnerability) {
    printf(vulnerability);
}

// Using examples from https://cwe.mitre.org/data/definitions/121.html
int stack_weakness(char* vulnerability) {
    char buf[BUFSIZE];
    strcpy(buf, vulnerability);
    printf(buf);
    return 0;
}

// Using examples from https://cwe.mitre.org/data/definitions/121.html
int heap_weakness(char* vulnerability) {
    char *buf;
    buf = (char *)malloc(sizeof(char)*BUFSIZE);
    strcpy(buf, vulnerability);
    printf(buf);
    return 0;
}

// Using example from https://cqr.company/web-vulnerabilities/integer-overflow/
/*
Here are some examples of exploiting integer overflow vulnerabilities:
    Buffer Overflow: An integer overflow vulnerability can lead to a buffer overflow attack, where the attacker overflows a buffer with data that exceeds its size, causing the program to crash or execute arbitrary code.
    Format String Attack: An integer overflow vulnerability can also be used to perform a format string attack, where the attacker inputs a specially crafted string that leads to a format string vulnerability in a function call.
    Heap Overflow: An integer overflow vulnerability can lead to a heap overflow attack, where the attacker overflows a heap-allocated buffer, leading to a heap-based buffer overflow.
    Integer Truncation Attack: An integer overflow vulnerability can also be used to perform an integer truncation attack, where the attacker inputs a large value that gets truncated when it is stored in a smaller data type, leading to unexpected results.
    Stack Overflow: An integer overflow vulnerability can lead to a stack overflow attack, where the attacker overflows a stack-allocated buffer, leading to a stack-based buffer overflow.
*/
int integer_weakness(int x, int y) {
    // int x = 2147483647;
    // int y = 2147483647;
    int z = x * y;
    printf("%d\n", z);
    return 0;
}

int dangling_pointer() {
    return 0;
}