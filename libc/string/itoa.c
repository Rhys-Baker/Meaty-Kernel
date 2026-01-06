#include <string.h>
#include <math.h>

int itoa(char *dest, int num, int base){
	char tmp[32];
	char *tp = tmp;
	int i;
	unsigned n;

	int sign = (base == 10 && num < 0);
	if (sign){
		n = -num;
	} else {
		n = (unsigned) num;
	}

	while(n || tp == tmp){
		i = n % base;
		n /= base;
		if(i < 10){
			*tp++ = i+'0';
		} else {
			*tp++ = i + 'a' - 10;
		}
	}

	int len = tp - tmp;

	if(sign)
	{
		*dest++ = '-';
		len++;
	}

	while(tp > tmp){
		*dest++ = *--tp;
	}

	*dest++ = '\0';

	return len;
}
