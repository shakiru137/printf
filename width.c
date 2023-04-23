#include "main.h"
/**
 *width - A function that calculates the width for printing
 */
int width(const char *formats, int *i, va_list list)
{
	int i;
	int wi = 0;
	for (i = *i + 1; formats[i] != '\0'; i++)
	{
		if (dig(formats[i]))
		{
			wi *= 10;
			wi += formats[i] - '0';
		}
		else if (formats[i] == '*')
		{
			i++;
			wi = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = i - 1;
	return(wi);
}

