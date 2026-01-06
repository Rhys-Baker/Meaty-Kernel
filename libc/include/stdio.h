#pragma once

#include <sys/cdefs.h>
#include <stddef.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*pfnStreamWriteBuf)(char*);

typedef struct Stream{
	size_t buf_len;
	size_t buf_i;
	char *buf;
	pfnStreamWriteBuf pfn_write_all;
} Stream;

extern Stream stdout;


int printf(const char *__restrict, ...);
int putchar(int);
int puts(const char *);

#ifdef __cplusplus
}
#endif
