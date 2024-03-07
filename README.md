# String Attacks


Within this project we tested different weak coding practices that lead to code injection vulnerabilities. Each one proved how code injection could be used to exploit poorly written code (code that does not handle data properly) to view data about the system or execute code not intended by the input. 

Each example given includes the outputs from weak_coding.c (actual) and secure_coding.c (expected). 

## Weak Coding Examples and Expectations
The following are the different vulnerabilities tested, with the expected and actual output. 


### Print Vulnerability
For print vulnerabilities, caution needs to be taken when handling inputted data to the code. The exact input should not be printed out, as an attacker could exploit this and grab system data if they provide format specifiers as an input. 

For example: 

Input: “./StringAttacks p "Hello World %p %p %p %p %p %p"”

Expected Output: “Hello World %p %p %p %p %p %p”

Actual Output: "Hello World 0x7ffce3b2ee48 0x55d6b63d8018 0x55d6b63d9d98 0x7f402ff2ef10 0x7f402ff4a040 0x6f0"


### Stack Buffer Overflow Vulnerability
Stack buffer overflow happens when data is copied into a variable that is too small to hold it. 

For example:

Buffer = 32 bytes

Input: "./StringAttacks s aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" (33 x a)

Expected Output: "0" (Did not write data past the buffer)

Actual Output: 

*** stack smashing detected ***: terminated

Aborted



### Heap Buffer Overflow Vulnerability
Heap buffer overflow is very similar to stack buffer overflow, however, instead of copying the input into a predefined size, the memory is dynamically allocated at runtime. Then the data is copied into this, causing the same issue if the input is larger than the dynamically allocated space.

For example: 

Buffer = 32 bytes

Input: "./StringAttacks h aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" (43 x a)

Expected Output: "0" (Did not write data past the buffer)

Actual Output: 

malloc(): corrupted top size

Aborted


### Integer Overflow Vulnerability
Integer overflow occurs when an integer variable exceeds the set bounds of an integer in C/C++. 

For example: For multiplying 2 integers

Input = "./StringAttacks i 2147483647 2147483647"

Expected Output: 

Values are too large, setting answer to 0.

0

Actual Output: "1"


### Dangling Pointer Vulnerability
Dangling pointers occur when a pointer is access/used after the pointers variable becomes unavailable or is removed. 

For example:

Input = "./StringAttacks d"

Expected Output: "No print because the dangling pointer has been set to NULL."

Actual Output: "ǮGX"
