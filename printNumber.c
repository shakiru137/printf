#include "main.h"
/*********************PRINT INTEGER************************/
/**
 * type_int - Function that print integer.
 * @type: The the incoming integer value.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags
 * @width: check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: Number of characters printed.
 */
int type_int(va_list type, char buffer[], int flag,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2; /* BUFF_SIZE is 1024 */
	int is_negative = 0;
	long int num = va_arg(type, long int);
	unsigned long int number;

	num = numberConv(num, size);

	if (num == 0)
		buffer[i--] = 0;

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)num;

	if (num < 0)
	{
		num = (unsigned long int)((-1) * num);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number = number / 10;
	}
	i++;

	return (handleNumber(is_negative, i, buffer, flag,
				width, precision, size));
}


/*********************PRINT UNSIGNED**********************/
/**
 * type_unsigned - Function that print unsigned number.
 * @types:  The unsigned integer to be printed.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags.
 * @width: To check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: The number of characters printed.
 */
int type_unsigned(va_list types, char buffer[], int flag,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2; /* BUFF_SIZE is 1024 */
	unsigned long int number = va_arg(types, unsigned long int);

	number = unsignedConv(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number = number / 10;
	}
	i++;

	return (handleUnsigned(0, i, buffer, flag, width, precision, size));
}
/*********************PRINT BINARY*************************/
/**
 * type_binary - Function that print unsigned integer.
 * @types:  The unsigned integer to be printed.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags.
 * @width: To check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: The number of characters printed.
 */
int type_binary(va_list types, char buffer[], int flag,
		int width, int precision, int size)
{
	unsigned int i, m, num, sum;
	unsigned int a[32] = {0};
	char z;
	int count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */

	for (i = 0, sum = 0; i < 32; i++, m = m >> 1)
	{
		if (num & m)
		{
			a[i] = 1;
			sum++;
		}
		if (sum || i == 31)
		{
			z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
		return (count);
	}
}


/*******************PRINT OCTALDECIMAL*********************/
/**
 * type_octal - Function that print octal number.
 * @types:  The unsigned integer to be printed.
 * @buffer: To handle the print.
 * @flag: To calculate the active flags.
 * @width: To check and assign width.
 * @precision: To specify the precision.
 * @size: To specify the size.
 *
 * Return: The number of characters printed.
 */
int type_octal(va_list types, char buffer[], int flag,
		int width, int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2; /* BUFF_SIZE */
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int num_init = number;

	UNUSED(width);

	number = unsignedConv(number, size);

	if (number == 0)
		buffer[i--] = '0';
	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number = number / 8;
	}

	if (flag & F_HASH && num_init != 0)
		buffer[i--] = '0';
	i++;

	return (handleUnsigned(0, i, buffer, flag, width, precision, size));
}
