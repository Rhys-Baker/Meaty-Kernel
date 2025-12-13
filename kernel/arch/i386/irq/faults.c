#include "../include/faults.h"

#include <stdio.h>

/* Division Error */
idt_entry idt_entry_division_error = {
    .offset = (uint32_t)&isr_division_error,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_division_error(struct interrupt_frame *frame){
    printf("\n ""\x1B\x0C""EXCEPTION: DIVISION ERROR. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Debug */
idt_entry idt_entry_debug = {
    .offset = (uint32_t)&isr_debug,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_debug(struct interrupt_frame *frame){
    printf("\n ""\x1B\x0C""EXCEPTION: DEBUG. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Non-Maskable Interrupt */
idt_entry idt_entry_non_maskable_interrupt = {
    .offset = (uint32_t)&isr_non_maskable_interrupt,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_non_maskable_interrupt(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: NON-MASKABLE INTERRUPT. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Breakpoint */
idt_entry idt_entry_breakpoint = {
    .offset = (uint32_t)&isr_breakpoint,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_breakpoint(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: BREAKPOINT HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Overflow */
idt_entry idt_entry_overflow = {
    .offset = (uint32_t)&isr_overflow,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_overflow(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: OVERFLOW. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Bound Range Exceeded */
idt_entry idt_entry_bound_range_exceeded = {
    .offset = (uint32_t)&isr_bound_range_exceeded,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_bound_range_exceeded(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: BOUND RANGE EXCEEDED. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Invalid Opcode */
idt_entry idt_entry_invalid_opcode = {
    .offset = (uint32_t)&isr_invalid_opcode,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_invalid_opcode(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: INVALID OPCODE. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Device Not Available */
idt_entry idt_entry_device_not_available = {
    .offset = (uint32_t)&isr_device_not_available,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_device_not_available(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: DEVICE NOT AVAILABLE. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Double Fault */
idt_entry idt_entry_double_fault = {
    .offset = (uint32_t)&isr_double_fault,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_double_fault(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: DOUBLE FAULT. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Coprocessor Segment Overrun (legacy) */
idt_entry idt_entry_coprocessor_segment_overrun = {
    .offset = (uint32_t)&isr_coprocessor_segment_overrun,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_coprocessor_segment_overrun(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: COPROCESSOR SEGMENT OVERRUN. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Invalid TSS */
idt_entry idt_entry_invalid_tss = {
    .offset = (uint32_t)&isr_invalid_tss,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_invalid_tss(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: INVALID TSS. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Segment Not Present */
idt_entry idt_entry_segment_not_present = {
    .offset = (uint32_t)&isr_segment_not_present,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_segment_not_present(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: SEGMENT NOT PRESENT. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Stack Segment Fault */
idt_entry idt_entry_stack_segment_fault = {
    .offset = (uint32_t)&isr_stack_segment_fault,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_stack_segment_fault(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: STACK SEGMENT FAULT. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* General Protection Fault */
idt_entry idt_entry_general_protection_fault = {
    .offset = (uint32_t)&isr_general_protection_fault,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_general_protection_fault(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: GENERAL PROTECTION FAULT.(0x%x) HALTING.""\x1B\x0F""\n", error_code);
    while(1) { asm volatile("hlt"); }
}

/* Page Fault */
idt_entry idt_entry_page_fault = {
    .offset = (uint32_t)&isr_page_fault,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_page_fault(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: PAGE FAULT. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* x87 Floating Point Exception */
idt_entry idt_x87_floating_point_exception = {
    .offset = (uint32_t)&isr_x87_floating_point_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_x87_floating_point_exception(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: X87 FLOATING POINT EXCEPTION HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Alignment Check */
idt_entry idt_alignment_check = {
    .offset = (uint32_t)&isr_alignment_check,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_alignment_check(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: ALIGNMENT CHECK. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Machine Check */
idt_entry idt_machine_check = {
    .offset = (uint32_t)&isr_machine_check,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_machine_check(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: MACHINE CHECK. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* SIMD Floating Point Exception */
idt_entry idt_simd_floating_point_exception = {
    .offset = (uint32_t)&isr_simd_floating_point_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_simd_floating_point_exception(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: SIMD FLOATING POINT EXCEPTION. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Virtualization Exception */
idt_entry idt_virtualization_exception = {
    .offset = (uint32_t)&isr_virtualization_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_virtualization_exception(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: VIRTUALIZATION EXCEPTION. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Control Protection Exception */
idt_entry idt_control_protection_exception = {
    .offset = (uint32_t)&isr_control_protection_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_control_protection_exception(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION:CONTROL PROTECTION EXCEPTION. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Hypervisor Injection Exception */
idt_entry idt_hypervisor_injection_exception = {
    .offset = (uint32_t)&isr_hypervisor_injection_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_hypervisor_injection_exception(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: HYPERVISOR INJECTION EXCEPTION. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* VMM Communication Exception */
idt_entry idt_vmm_communication_exception = {
    .offset = (uint32_t)&isr_vmm_communication_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_vmm_communication_exception(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: VMM COMMUNICATION EXCEPTION. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* Security Exception */
idt_entry idt_security_exception = {
    .offset = (uint32_t)&isr_security_exception,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_security_exception(struct interrupt_frame *frame, uint32_t error_code) {
    printf("\n ""\x1B\x0C""EXCEPTION: SECURITY EXCEPTION. HALTING.""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}

/* FPU Error Interrupt (legacy) */
idt_entry idt_fpu_error_interrupt = {
    .offset = (uint32_t)&isr_fpu_error_interrupt,
    .selector = 0x08,
    .type_attributes = 0x8E
};
__attribute__((interrupt, noinline)) void isr_fpu_error_interrupt(struct interrupt_frame *frame) {
    printf("\n ""\x1B\x0C""EXCEPTION: FPU ERROR INTERRUPT""\x1B\x0F""\n");
    while(1) { asm volatile("hlt"); }
}


void encode_faults(){
    encode_idt_entry(idt[0], idt_entry_division_error);
    encode_idt_entry(idt[1], idt_entry_debug);
    encode_idt_entry(idt[2], idt_entry_non_maskable_interrupt);
    encode_idt_entry(idt[3], idt_entry_breakpoint);
    encode_idt_entry(idt[4], idt_entry_overflow);
    encode_idt_entry(idt[5], idt_entry_bound_range_exceeded);
    encode_idt_entry(idt[6], idt_entry_invalid_opcode);
    encode_idt_entry(idt[7], idt_entry_device_not_available);
    encode_idt_entry(idt[8], idt_entry_double_fault);
    encode_idt_entry(idt[9], idt_entry_coprocessor_segment_overrun);
    encode_idt_entry(idt[10], idt_entry_invalid_tss);
    encode_idt_entry(idt[11], idt_entry_segment_not_present);
    encode_idt_entry(idt[12], idt_entry_stack_segment_fault);
    encode_idt_entry(idt[13], idt_entry_general_protection_fault);
    encode_idt_entry(idt[14], idt_entry_page_fault);
    /* Reserved */
    encode_idt_entry(idt[16], idt_x87_floating_point_exception);
    encode_idt_entry(idt[17], idt_alignment_check);
    encode_idt_entry(idt[18], idt_machine_check);
    encode_idt_entry(idt[19], idt_simd_floating_point_exception);
    encode_idt_entry(idt[20], idt_virtualization_exception);
    encode_idt_entry(idt[21], idt_control_protection_exception);
    /* Reserved 22-27 */
    encode_idt_entry(idt[28], idt_hypervisor_injection_exception);
    encode_idt_entry(idt[29], idt_vmm_communication_exception);
    encode_idt_entry(idt[30], idt_security_exception);
    
}