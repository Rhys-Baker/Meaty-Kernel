#pragma once
#include "idt.h"

extern idt_entry idt_entry_keyboard_interrupt;

__attribute__((interrupt, noinline)) void isr_keyboard_interrupt(struct interrupt_frame *frame);
