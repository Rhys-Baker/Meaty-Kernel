#pragma once

struct interrupt_frame;

__attribute__((interrupt)) void isr_div0(struct interrupt_frame *frame);