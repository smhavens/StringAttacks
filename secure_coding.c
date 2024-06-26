// Main file with poorly implemented code leaving room for attacks on the OS.
// Included attacks:
// poor string formatting
// stack and heap buffer overflows
// integer vulnerabilities
// and finally dangling pointers.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "secure_coding.h"

#define BUFSIZE 32
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int main(int argc, char** argv) {

    char option = argv[1][0];

    switch(option){
        case 'p':
            // Poor formatting, user can insert commands.
            print_secure(argv[2]);
            break;

        case 's':
            // Stack Buffer Overflow
            stack_secure(argv[2]);
            break;

        case 'h':
            // Heap Buffer Overflow
            heap_secure(argv[2]);
            break;

        case 'i':
            // Integer Vulnerabilities
            integer_secure(atoi(argv[2]), atoi(argv[3]));
            break;

        case 'd':
            // Dangling Pointers
            secure_pointer();
            break;
        default:
            printf("Have a nice day!\n");
    }
    
}

void print_secure(char* vulnerability) {
    printf("%s\n", vulnerability);
    // Example output from tool is
    // Print Vulnerability detected on line 49, possible solution is 'printf("%s", vulnerability);' to sanitize input.
}

// Using examples from https://cwe.mitre.org/data/definitions/121.html
// Another good example is from https://www.thegeekstuff.com/2013/06/buffer-overflow/
int stack_secure(char* vulnerability) {
    char buf[BUFSIZE];
    int pass = 0;
    strncpy(buf, vulnerability, BUFSIZE);
    printf("%d\n", pass);
    return 0;

    // Stack Buffer Overflow Vulnerability detected on line 58, possible solution is 'strncpy(buf, vulnerability);' to ensure length.
}

// Using examples from https://cwe.mitre.org/data/definitions/121.html
int heap_secure(char* vulnerability) {
    char *buf;
    buf = (char *)malloc(sizeof(char)*BUFSIZE);
    int pass = 0;
    strncpy(buf, vulnerability, BUFSIZE);
    printf("%d\n", pass);
    return 0;

    // Heap Buffer Overflow Vulnerability detected on line 69, possible solution is 'strncpy(buf, vulnerability);' to ensure length.
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
int integer_secure(int x, int y) {
    // int x = 2147483647;
    // int y = 2147483647;
    int z = 0;
    if (!(y > INT_MAX / x || y < INT_MIN / x)) {
        z = x * y;
    }
    else {
        // int z = 0;
        printf("Values are too large, setting answer to 0.\n");
    }
    printf("%d\n", z);
    return 0;

    // Integer Overflow Vulnerability detected on line 88, possible solution is 
    // 88 'if (x != 0 ? y > INT_MAX / x : y < INT_MIN / x) {' 
    // 89 'int z = x * y;'
    // 90 '}' 
    // to ensure fits into integer.
}

//code from https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/
int secure_pointer() {

    int* ptr = (int*)malloc(sizeof(int));
    // int* bad_ptr = ptr;

    // This makes ptr point to something we don't know!
    free(ptr);
    ptr = NULL;

    printf(ptr);

    return 0;

    // Dangling Pointer Vulnerability detected on line 106, possible solution is to add 'ptr = NULL;' on line 107.
}