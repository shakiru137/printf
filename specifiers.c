#include "main.h"
/**
 * flags - A function that calculates active flags
 * @format: Format of the pointer
 * @i: Pointer.
 *
 * Return: flag on SUCCESS.
 */
int flags(const char *format, int *i)
{
	int k, cu_i;
	int flag = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cu_i = *i + 1; format[cu_i] != '\0'; cu_i++)
	{

		for (k = 0; FLAGS_CHAR[k] != '\0'; k++)
			if (format[cu_i] == FLAGS_CHAR[k])
			{
				flag |= FLAGS_ARRAY[k];
				break;
			}
		if (FLAGS_CHAR[k] == 0)
			break;
	}
	*i = cu_i - 1;
	return (flag);
}
/**
 * precision  - A function that calculates the precision for printing.
 * @format: Format of the character.
 * @i: Pointer.
 * @list: Contains the value.
 *
 * Return: precision on SUCCESS.
 */
int precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int prec = -1;

	if (format[cu_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (dig(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
/**
 * size - A function that calculates the size to cast the argument
 * @format: Format of the character.
 * @i: Pointer.
 *
 * Return: size on SUCCESS.
 */
int size(const char *format, int *i)
{
	int cu_i = *i + 1;
	int sizes = 0;

	if (format[cu_i] == 'l')
		sizes = S_LONG;
	else if (format[cu_i] == 'h')
		sizes = S_SHORT;

	if (sizes == 0)
		*i = cu_i - 1;
	else
		*i = cu_i;
	return (sizes);
}
/**
 * width - A function that calculates the width for printing
 * @format: Format of the charater.
 * @i: Pointer.
 * @list: The incoming value.
 *
 * Return: wi on SUCCESS.
 */
int width(const char *format, int *i, va_list list)
{
	int cu_i;
	int wi = 0;

	for (cu_i = *i + 1; format[cu_i] != '\0'; cu_i++)
	{
		if (dig(format[cu_i]))
		{
			wi *= 10;
			wi += format[cu_i] - '0';
		}
		else if (format[cu_i] == '*')
		{
			cu_i++;
			wi = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = cu_i - 1;
	return (wi);
}
