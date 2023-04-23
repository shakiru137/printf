#include "main.h"
/*
 * flag - A Function that calculates the active flags
 */
int flag(const char *formats, int *i)
	int f,i;
	int flag = 0;
	const char FLAG_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	for (i = *i + 1; formats[i] != '\0'; i++)
	{
		for (f = 0; FLAG_CHAR[f] != '\0'; f++)
			if (formatS[i] == FLAG_CHAR[f])
			{
				flag |= FLAG_ARRAY[f];
				break;
			}
		if (FLAG_CHAR[f] == 0)
			break;
	}
	*i = i - 1;
	return (flag);
}
