#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

extern bool escaped;
void terminal_init(void);
void terminal_setcolor(uint8_t color);
void terminal_putchar(char c);
void terminal_write(const char *data, size_t size);
void terminal_writestring(const char *data);