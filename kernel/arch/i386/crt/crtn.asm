SECTION .init
    ; GCC will put the contents of crtend.o's .init section here.
    pop ebp
    ret

SECTION .fini
    ; GCC will put the contents of crtend.o's .fini section here.
    pop ebp
    ret