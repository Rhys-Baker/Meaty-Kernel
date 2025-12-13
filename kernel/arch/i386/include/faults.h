#pragma once
#include "idt.h"

// IDT Entries for each exception
extern idt_entry idt_entry_division_error;
extern idt_entry idt_entry_debug;
extern idt_entry idt_entry_non_maskable_interrupt;
extern idt_entry idt_entry_breakpoint;
extern idt_entry idt_entry_overflow;
extern idt_entry idt_entry_bound_range_exceeded;
extern idt_entry idt_entry_invalid_opcode;
extern idt_entry idt_entry_device_not_available;
extern idt_entry idt_entry_double_fault;
extern idt_entry idt_entry_coprocessor_segment_overrun;
extern idt_entry idt_entry_invalid_tss;
extern idt_entry idt_entry_segment_not_present;
extern idt_entry idt_entry_stack_segment_fault;
extern idt_entry idt_entry_general_protection_fault;
extern idt_entry idt_entry_page_fault;
extern idt_entry idt_x87_floating_point_exception;
extern idt_entry idt_alignment_check;
extern idt_entry idt_machine_check;
extern idt_entry idt_simd_floating_point_exception;
extern idt_entry idt_virtualization_exception;
extern idt_entry idt_control_protection_exception;
extern idt_entry idt_hypervisor_injection_exception;
extern idt_entry idt_vmm_communication_exception;
extern idt_entry idt_security_exception;
extern idt_entry idt_fpu_error_interrupt;

// Declare ISRs for the 32 reserved interrupts (faults/exceptions)
__attribute__((interrupt, noinline)) void isr_division_error(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_debug(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_non_maskable_interrupt(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_breakpoint(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_overflow(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_bound_range_exceeded(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_invalid_opcode(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_device_not_available(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_double_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_coprocessor_segment_overrun(struct interrupt_frame *frame); /* Legacy, no longer used */
__attribute__((interrupt, noinline)) void isr_invalid_tss(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_segment_not_present(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_stack_segment_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_general_protection_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_page_fault(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_x87_floating_point_exception(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_alignment_check(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_machine_check(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_simd_floating_point_exception(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_virtualization_exception(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_control_protection_exception(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_hypervisor_injection_exception(struct interrupt_frame *frame);
__attribute__((interrupt, noinline)) void isr_vmm_communication_exception(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_security_exception(struct interrupt_frame *frame, uint32_t error_code);
__attribute__((interrupt, noinline)) void isr_fpu_error_interrupt(struct interrupt_frame *frame); /* Legacy, no longer used */

void encode_faults();