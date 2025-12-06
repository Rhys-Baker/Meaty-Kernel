#include <stdio.h>

#include <kernel/tty.h>


const char *testString = "This is a test string.\nIt tests \x1B\x0AMOST\x1B\x0F features of the terminal.\n";

void kernel_main(void){
    terminal_init();
    printf("Hello, World!\n");
    printf("%c", testString);
    printf("\nDone.\n");
}