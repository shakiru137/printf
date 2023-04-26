#include "main.h"
/**
* aug_type - Prints an argument based on its type
* @fmt: Formatted string in which to print the arguments.
* @list: List of arguments to be printed.
* @ind: ind.
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: 1 or 2;
*/
int aug_type(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	formatType fmt_types[] = {
	{'c', chars}, {'s', strings}, {'%', percents},
	{'i', type_int}, {'d', type_int}, {'b', type_binary},
	{'u', type_unsigned}, {'o', type_octal}, {'x', type_hexadecimal},
	{'X', type_hexa_upper}, {'p', memory}, {'S', nonPrint},
	{'r', reverse}, {'R', rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	if (fmt[*ind] == fmt_types[i].fmt)
	return (fmt_types[i].k(list, buffer, flags, width, precision, size));
	if (fmt_types[i].fmt == '\0')
	{
	if (fmt[*ind] == '\0')
	return (-1);
	unknow_len += write(1, "%%", 1);
	if (fmt[*ind - 1] == ' ')
	unknow_len += write(1, " ", 1);
	else if (width)
	{
	--(*ind);
	while (fmt[*ind] != ' ' && fmt[*ind] != '%')
	--(*ind);
	if (fmt[*ind] == ' ')
	--(*ind);
	return (1);
	}
	unknow_len += write(1, &fmt[*ind], 1);
	return (unknow_len);
	}
	return (printed_chars);
}
