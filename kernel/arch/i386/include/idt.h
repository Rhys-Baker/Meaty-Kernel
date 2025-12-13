#pragma once
#include <stdint.h>

typedef struct idt_entry {
    uint32_t offset;
    uint16_t selector;
    uint8_t type_attributes;
} idt_entry;


extern uint8_t idt[256][8];

extern void load_idt(uint16_t limit, uint32_t base);


void init_idt(void);
void encode_idt_entry(uint8_t *target, idt_entry source);


