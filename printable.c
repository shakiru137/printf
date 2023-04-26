#include "main.h"
/**
 * printable - A function that evaluates if a specific char is printable
 */
int printable(char c)
{
	if (c < 127 && c >= 32)
		return (1);
	return (0);
}
/**
 * hexaCode - A function to append ascii
 */
int hexaCode(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * dig - A function that checks if a char is a digit
 */
int dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * numberConv - A function that casts a number to the required size
 */
long int numberConv(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * unsignedConv - Casts a number to the required size
 */
long int unsignedConv(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

