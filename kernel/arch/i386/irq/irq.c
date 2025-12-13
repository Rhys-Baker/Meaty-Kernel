#include "../include/irq.h"

#include "../include/pic.h"

#include <stdio.h>

static const char scancode_to_ascii[128] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','Q','W','E','R','T','Y','U','I','O','P','[',']','\n',
    0,   'A','S','D','F','G','H','J','K','L',';','\'','`',
    0,  '\\','Z','X','C','V','B','N','M',',','.','/', 0,
    '*', 0,  ' ', 0,
};


idt_entry idt_entry_keyboard_interrupt = {
    .offset = (uint32_t)&isr_keyboard_interrupt,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_keyboard_interrupt(struct interrupt_frame *frame){
    uint8_t scan_code = inb(0x60);

    if(scan_code & 0x80){
        outb(0x20, 0x20);
        return;
    }

    putchar(scancode_to_ascii[scan_code]);
    
    outb(0x20, 0x20);
}