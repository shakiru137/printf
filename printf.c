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
	int i, print = 0, printed = 0;
	int flag, width, precision, size, buffHand = 0;
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
			printed(buffer, &buffHand);
			flag = get_flag(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printedHand = handle_print(format, &i, list, buffer,
				flag, width, precision, size);
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
