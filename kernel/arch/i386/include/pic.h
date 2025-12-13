#pragma once

#include "io.h"

#define PIC1         0x20		/* IO base address for master PIC */
#define PIC2         0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND PIC1
#define PIC1_DATA    (PIC1+1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA    (PIC2+1)
#define PIC_EOI      0x20		/* End-of-interrupt command code */

/* reinitialize the PIC controllers, giving them specified vector offsets
   rather than 8h and 70h, as configured by default */
#define ICW1_ICW4   0x01		/* Indicates that ICW4 will be present */
#define ICW1_SINGLE 0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4 0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL  0x08		/* Level triggered (edge) mode */
#define ICW1_INIT   0x10		/* Initialization - required! */
#define ICW4_8086   0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO   0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE  0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER 0x0C		/* Buffered mode/master */
#define ICW4_SFNM    0x10		/* Special fully nested (not) */
#define CASCADE_IRQ 2

#define PIC_READ_IRR 0x0a    /* OCW3 irq ready next CMD read */
#define PIC_READ_ISR 0x0b    /* OCW3 irq service next CMD read */


/// @brief Send the End Of Interrupt control signal to the PIC(s)
/// @param irq IRQ number that was serviced.
void pic_send_eoi(uint8_t irq);

/// @brief Initialise the PIC controllers.
/// @param offset1 Vector offset for the master PIC. Vectors become offset1..offset1+7
/// @param offset2 Vector offset for the slave PIC. Vectors become offset1..offset1+7
void pic_remap(int offset1, int offset2);

/// @brief Every interrupt must be masked (essentially disabling the PIC chips) before using the processor local APIC and the IOAPIC.
void pic_disable(void);

/// @brief Masks (disables) a specific IRQ line
/// @param irq_line The number for the IRQ line to disable (0..7/8..15)
void irq_set_mask(uint8_t irq_line);

/// @brief Unmasks (enables) a specific IRQ line
/// @param irq_line The number for the IRQ line to enable (0..7/8..15)
void irq_clear_mask(uint8_t irq_line);

/// @brief  Get the combined value of the cascaded PICs irq request register
/// @return Cascaded PICs IRR value
uint16_t pic_get_irr(void);

/// @brief Get the combined value of the cascaded PICs in-service register
/// @return Cascaded PICs ISR value
uint16_t pic_get_isr(void);

void pic_ack(void);

/// @brief Initialise the PIC chip, remap IRQs, and set every bit in the mask
void pic_init(void);