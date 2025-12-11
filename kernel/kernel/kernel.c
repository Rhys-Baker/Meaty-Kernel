#include <stdio.h>

#include <kernel/tty.h>


const char *testString = "This is a test string.\nIt tests \x1B\x0AMOST\x1B\x0F features of the terminal.\n";

void kernel_main(void){
    terminal_init();
    printf("Hello, World!\n");
    printf("Test char: %c %c %c\n", 'A', 'B', 'C');
    printf("Test string: %s\n", testString);
    printf("Hex number: 0x%x\n", 0x1234ABCD);
    printf("\nDone.\n");
}