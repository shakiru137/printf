#include "main.h"
/**
 * size - The function calculates the size to cast the argument
 */
int size(const char *formats, int *i)
{
	int i = *i + 1;
	int sizes = 0;
	if (formats[i] == 'l')
		sizes = S_LONG;
	else if (formats[i] == 'h')
		sizes = S_SHORT;
	if (sizes == 0)
		*i = i - 1;
	else
		*i = i;
	return(sizes);
}
