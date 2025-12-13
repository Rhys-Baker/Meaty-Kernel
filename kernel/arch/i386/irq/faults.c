#include "../include/faults.h"

#include <stdio.h>

__attribute__((interrupt, noinline)) void isr_division_error(struct interrupt_frame *frame){
    printf("\n ""\x1B\x0C""EXCEPTION: DIVISION ERROR. HALTING.""\x1B\x0F""\n");
    
    while(1) { asm volatile("hlt"); }

}