#include "main.h"
/**
 * precision - A function that calculates the precision for printing
 */
int precision(const char *formats, int *i, va_list list)
{
	int i = *i + 1;
	int prec = -1;
	if (formats[i] != '.')
		return(prec);
	prec = 0;
	for (i += 1; formats[i] != '\0'; i++)
	{
		if (dig(formats[i]))
		{
			prec *= 10;
			prec += formats[i] - '0';
		}
		else if (formats[i] == '*')
		{
			i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = i - 1;
	return(prec);
}

