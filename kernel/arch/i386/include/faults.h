#pragma once
#include "idt.h"

struct interrupt_frame {
    unsigned int eip;
    unsigned int cs;
    unsigned int flags;
    unsigned int sp;
    unsigned int ss;
};

// Declare ISRs for the 32 reserved interrupts (faults/exceptions)
__attribute__((interrupt, noinline)) void isr_division_error(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_debug(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_non_maskable_interrupt(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_breakpoint(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_overflow(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_bound_range_exceeded(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_invalid_opcode(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_device_not_available(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_double_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_coprocessor_segment_overrun(struct interrupt_frame *frame); /* Legacy, no longer used */
__attribute__((interrupt)) void isr_invalid_tss(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_segment_not_present(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_stack_segment_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_general_protection_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_page_fault(struct interrupt_frame *frame, uint32_t error_code);
/* Reserved */
__attribute__((interrupt)) void isr_x87_floating_point_exception(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_alignment_check(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_machine_check(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_simd_floating_point_exception(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_virtualization_exception(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_control_protection_exception(struct interrupt_frame *frame, uint32_t error_code);
/* Reserved */
__attribute__((interrupt)) void isr_hypervisor_injection_exception(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_vmm_communication_exception(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt)) void isr_security_exception(struct interrupt_frame *frame, uint32_t error_code);
/* Reserved */
//__attribute__((interrupt)) void isr_triple_fault(struct interrupt_frame *frame);
__attribute__((interrupt)) void isr_fpu_error_interrupt(struct interrupt_frame *frame); /* Legacy, no longer used */

