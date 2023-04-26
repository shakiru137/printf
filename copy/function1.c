#include "main.h"
/************************* PRINT CHAR *************************/
/**
 * chars - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int chars(va_list types, char buffer[],
		int flag, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handleChar(c, buffer, flag, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * strings - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int strings(va_list types, char buffer[],
		int flag, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * percents - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int percents(va_list types, char buffer[],
		int flag, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
