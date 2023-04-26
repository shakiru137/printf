#include "main.h"
/******************PRINT HEXA UPPER************************/
/**
 * type_hexa_upper - Function that print hexa upper number.
 * @types:  The unsigned integer to be printed.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags.
 * @width: To check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: The number of characters printed.
 */
int type_hexa_upper(va_list types, char buffer[], int flag,
		int width, int precision, int size)
{
	return (type_hexa(types, "0123456789ABCDEF", buffer,
				flag, 'X', width, precision, size));
}


/****************UPPER or LOWER HEXADECIMAL****************/
/**
 * type_hexa - Function that print hexa in lower and upper number.
 * @types:  The unsigned integer to be printed.
 * @map_to: Array of value to map the calue to.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags.
 * @flagCharater: Calculate active flags.
 * @width: To check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: The number of characters printed.
 */
int type_hexa(va_list types, char map_to[], char buffer[],
		int flag, char flagCharater, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int num_init = number;

	UNUSED(width);

	number = unsignedConv(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = map_to[number % 16];
	}

	if (flag & F_HASH && num_init != 0)
	{
		buffer[i--] = flagCharater;
		buffer[i--] = '0';
	}
	i++;

	return (handleUnsigned(0, i, buffer, flag, width, precision, size));
}



/*********************PRINT HEXADECIMAL********************/
/**
 * type_hexadecimal - Function that print hexadecimal number.
 * @types:  The unsigned integer to be printed.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags.
 * @width: To check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: The number of characters printed.
 */
int type_hexadecimal(va_list types, char buffer[], int flag,
		int width, int precision, int size)
{
	return (type_hexa(types, "0123456789abcdef", buffer,
				flag, 'x', width, precision, size));
}
