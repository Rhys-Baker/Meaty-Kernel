#include <stdio.h>

int puts(const char *string){
    int i=0;
    while(string[i]){
        if(putchar(string[i]) == EOF){
            return EOF;
        }
        i++;
    }
    if(putchar('\n') == EOF){
        return EOF;
    }
    return 1;
}