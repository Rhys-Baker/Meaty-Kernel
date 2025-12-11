#include <stdio.h>

#include <kernel/gdt.h>
#include <kernel/tty.h>

void kernel_main(void){
    terminal_init();
    printf("Initialising GDT.\n");
    init_gdt();
    printf(
        "GDT:\n"
        "0:\n"
        " 0x%x 0x%x\n 0x%x 0x%x\n 0x%x 0x%x\n 0x%x 0x%x\n"
        "1:\n"
        " 0x%x 0x%x\n 0x%x 0x%x\n 0x%x 0x%x\n 0x%x 0x%x\n"
        "2:\n"
        " 0x%x 0x%x\n 0x%x 0x%x\n 0x%x 0x%x\n 0x%x 0x%x\n",
        gdt[0][0],gdt[0][1],gdt[0][2],gdt[0][3],
        gdt[0][4],gdt[0][5],gdt[0][6],gdt[0][7],
        
        gdt[1][0],gdt[1][1],gdt[1][2],gdt[1][3],
        gdt[1][4],gdt[1][5],gdt[1][6],gdt[1][7],

        gdt[2][0],gdt[2][1],gdt[2][2],gdt[2][3],
        gdt[2][4],gdt[2][5],gdt[2][6],gdt[2][7]
    );
    
    printf("\nDone.\n");
}