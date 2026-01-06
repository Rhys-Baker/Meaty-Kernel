#include <stdio.h>

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static bool print(const char *data, size_t length){
    const unsigned char *bytes = (const unsigned char *)data;
    for(size_t i=0; i<length; i++){
        if(putchar(bytes[i]) == EOF){
            return false;
        }
    }
    return true;
}

int printf(const char *restrict format, ...){
    va_list args;
    va_start(args, format);

    while(*format){
        if(*format == '%'){
            format++;
            switch(*format){
                case 'c':
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    break;
                case 's':
                    char *str = (char *)va_arg(args, int);
                    print(str, strlen(str));
                    break;
				case 'd':
					char intstr[12]; // 1 for sign, 11 for value, 1 for null
					unsigned int d_integer = va_arg(args, int);
					itoa(intstr, d_integer, 10);
					print(intstr, strlen(intstr));
					break;
                case 'x':
                    char hexstr[9];    
                    unsigned int x_integer = va_arg(args, int);
                    for(int i=0; i<8; i++){
                        unsigned int x_nibble = (x_integer >> (28 - 4*i)) & 0xF;
                        hexstr[i] = (x_nibble < 10) ? ('0' + x_nibble) : ('A' + x_nibble-10);
                    }
                    hexstr[8] = '\0';
                    print(hexstr, 8);
                    break;
                default:
                    // Unknown format
                    va_end(args);
                    return EOF;
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }
    va_end(args);
    
    return 0;
}
