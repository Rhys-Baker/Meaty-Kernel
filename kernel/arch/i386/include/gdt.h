#pragma once
#include <stdint.h>

typedef struct gdt_entry {
    unsigned int base;
    unsigned int limit;
    uint8_t access_byte;
    uint8_t flags;
} gdt_entry;

extern uint8_t gdt[5][8];

extern void load_gdt(uint16_t limit, uint32_t base);
extern void reload_segments();
void init_gdt(void);
void encode_gdt_entry(uint8_t *target, gdt_entry source);

