/* The bootloader will look at this image and start execution at the symbol
   Designated by the ENTRY keyword */
ENTRY(_start)

/* Tell where each section will be put in the final image */
SECTIONS
{
    /* Begin by putting sections at 2MiB. */
    . = 2M;

    /* First, put the multiboot header */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    /* Read-Only data */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* Read-Write data (initialised) */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* Read-Write data (un-initialised) */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }

    /* The compiler may produce other sections. They should be put
       in their proper place in this file. */
}