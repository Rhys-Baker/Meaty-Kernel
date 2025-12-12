#include "../include/faults.h"

__attribute__((interrupt)) void isr_div0(struct interrupt_frame *frame){
    // Do Nothing
    __asm__ volatile("nop");
}