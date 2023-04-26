#include "main.h"
/**
 * aug_type - Fuctiin that prints argument base on it types.
 * @fmt: string to print arguments.
 * @i: Pointer pointing to index of all argument to be printed.
 * @list: arguments to be printed.
 * @buffer: array of buffer to handle print.
 * @flag: get the active flags.
 * @width: width specifier.
 * @precision: precision specifier.
 * @size: size specifiers.
 *
 * Return: int.
 */
int aug_type(const char *fmt, int *i, va_list list, char buffer[],
		int flag, int width, int precision, int size)
{
	int j, unknow_length = 0, printed_ch = -1;
	formatType fmt_types[] = {
		{'c', chars}, {'s', strings}, {'%', percents},
		{'i', type_int}, {'d', type_int}, {'b', type_binary},
		{'u', type_unsigned}, {'o', type_octal}, {'x', type_hexadecimal},
		{'X', type_hexa_upper}, {'p', memory}, {'S', nonPrint},
		{'r', reverse}, {'R', rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
		if (fmt[*i] == fmt_types[j].fmt)
			return (fmt_types[j].k(list, buffer, flag, width,
					precision, size));
	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*i] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (fmt[*i - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (fmt[*i] != ' ' && fmt[*i] != '%')
				--(*i);
			if (fmt[*i] == ' ')
				--(*i);
			return (1);
		}
		unknow_length += write(1, &fmt[*i], 1);
		return (unknow_length);
	}
	return (printed_ch);
}


