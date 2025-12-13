#include "include/idt.h"

#include "include/faults.h"
#include "include/isr.h"
#include "include/irq.h"

uint8_t idt[256][8];

void encode_idt_entry(uint8_t *target, idt_entry source){
    // Offset_1
    target[0] = source.offset & 0xFF;
    target[1] = (source.offset >> 8) & 0xFF;

    // Selector
    target[2] = source.selector & 0xFF;
    target[3] = (source.selector >> 8) & 0xFF;
    
    // Zero
    target[4] = 0x00;

    // Type Attributes
    target[5] = source.type_attributes;

    // Offset_2
    target[6] = (source.offset >> 16) & 0xFF;
    target[7] = (source.offset >> 24) & 0xFF;
}

void init_idt(void){
    // Zero the entire IDT
    for (int i = 1; i < 256; i++)
        for (int j = 0; j < 8; j++)
            idt[i][j] = 0;

    idt_entry idt_entry_division_error = {
        .offset = (uint32_t)&isr_division_error,
        .selector = 0x08, /* Code segment */
        .type_attributes = 0x8E /* 32-bit interrupt gate in ring 0 */
    };
    encode_idt_entry(idt[0], idt_entry_division_error);


    uint16_t limit = sizeof(idt) - 1;
    uint32_t base = (uint32_t)&idt;
    load_idt(limit, base);
    return;
}