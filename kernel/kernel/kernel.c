#include <stdio.h>

#include <kernel/tty.h>

#include "../arch/i386/include/gdt.h"
#include "../arch/i386/include/idt.h"
#include "../arch/i386/include/pic.h"

#include "../arch/i386/include/faults.h"

void kernel_main(void){
    int a = 1;

    terminal_init();
    printf("Initialising GDT... ");
    init_gdt();
    printf("\x1B\x0A""OK.""\x1B\x0F""\n");

    printf("Initialising IDT... ");
    init_idt();
    printf("\x1B\x0A""OK.""\x1B\x0F""\n");

    printf("Initialising PIC... ");
    pic_init();
    printf("\x1B\x0A""OK.""\x1B\x0F""\n");
    
    printf("Enabling interrupts... ");
    __asm__ volatile("sti");
    printf("\x1B\x0A""OK.""\x1B\x0F""\n");

    printf("Testing Division Error ISR...\n");
    a=1/0;
    printf("Variable a = 0x%x\n", a);
}