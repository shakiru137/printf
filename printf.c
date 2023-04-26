#include "main.h"
void print_buffer(char buffer[], int *buffHand);
/**
 * _printf - Function that print variables.
 * @format: The variable type.
 *
 * Return: int (SUCCESS).
 */
int _printf(const char *format, ...)
{
	int i, printedHand = 0, printed = 0;
	int flag, widths, precisions, sizes, buffHand = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffHand++] = format[i];
			if (buffHand == BUFF_SIZE)
				print_buffer(buffer, &buffHand);
			printed++;
		}
		else
		{
			print_buffer(buffer, &buffHand);
			flag = g_flags(format, &i);
			widths = g_width(format, &i, list);
			precisions = g_precision(format, &i, list);
			sizes = g_size(format, &i);
			++i;
			printedHand = aug_type(format, &i, list, buffer,
				flag, widths, precisions, sizes);
			if (printedHand == -1)
				return (-1);
			printed += printedHand;
		}
	}
	print_buffer(buffer, &buffHand);
	va_end(list);
	return (printedHand);
}

/**
 * print_buffer - Function that that handle the print.
 * @buffer: Arays of value in the buffer.
 * @buffHand: Pointer.
 *
 * Return: Nothing.
 */
void print_buffer(char buffer[], int *buffHand)
{
	if (*buffHand > 0)
		write(1, &buffer[0], *buffHand);
	*buffHand = 0;
}
