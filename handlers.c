#include "main.h"
/***************************HANDLE CHARACTERS******************************/
/**
 * handleChar - Print a string.
 * @c: character type.
 * @buffer: Array to handle print.
 * @flag: calculates active flags.
 * @width: get the width.
 * @precision: precision specifiers.
 * @size: size specifier.
 *
 * Return: value stored in buffer.
 */
int handleChar(char c, char buffer[],
		int flag, int width, int precision, int size)
{
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_ZERO)
		padding = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padding;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}


/******************************HANDLE NUM*********************************/
/**
 * handleNum - Write a number using a buffer
 * @indx: The indx at which the number starts on the buffer.
 * @orr: The buffer.
 * @flag: The flags.
 * @width: The width.
 * @precision: The precision specifier.
 * @length: The number of length.
 * @d: padding character.
 * @ch: The extra character.
 * Return: Number of printed characters.
 */
int handleNum(int indx, char orr[], int flag, int width,
		int precision, int length, char d, char ch)
{
	int i, d_start = 1;

	if (precision == 0 && indx == BUFF_SIZE - 2 &&
			orr[indx] == '0' && width == 0)
		return (0);
	if (precision == 0 && indx == BUFF_SIZE - 2 && orr[indx] == '0')
		orr[indx] = d = ' ';
	if (precision > 0 && precision < length)
		d = ' ';
	while (precision > length)
		orr[--indx] = '0', length++;
	if (ch != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			orr[i] = d;
		orr[i] = '\0';
		if (flag & F_MINUS && d == ' ')
		{
		if (ch)
			orr[--indx] = ch;
		return (write(1, &orr[indx], length) + write(1, &orr[1], i - 1));
		}
		else if (!(flag & F_MINUS) && d == ' ')
		{
		if (ch)
			orr[--indx] = ch;
return (write(1, &orr[1], i - 1) + write(1, &orr[indx], length));
		}
		else if (!(flag & F_MINUS) && d == '0')
		{
		if (ch)
			orr[--d_start] = ch;
		return (write(1, &orr[d_start], i - d_start) +
		write(1, &orr[indx], length - (1 - d_start)));
		}
	}
	if (ch)
		orr[--indx] = ch;
	return (write(1, &orr[indx], length));
}


/*******************************HANDLE NUMBER******************************/
/**
 * handleNumber - function that return an integer value which is the
 * number of characters written to the buffer.
 * @positive: Indicates if the number to be written is positive or not
 * @indx: Represents the starting indx of the buffer
 * @buffer: Array (string) that contains the number to be written
 * @flag: Contains the flags for the conversion
 * @width: Represents the minimum width of the output
 * @precision: An integer value that represents the precision of the output
 * @size: Represents the maximum size of the buffer
 *
 * Return: pnteger value.
 */
int handleNumber(int positive, int indx, char buffer[], int flag,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - indx - 1;
	char padding = ' ';
	char extra_c = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padding = '0';
	if (positive)
		extra_c = '-';
	else if (flag & F_PLUS)
		extra_c = '+';
	else if (flag & F_SPACE)
		extra_c = ' ';
	return (handleNum(indx, buffer, flag, width, precision, length,
				padding, extra_c));
}



/**
 * handlePointer - Function that write the memory address.
 * @buffer: Arrays of characters.
 * @indx: indx at wgich the number start in the buffer.
 * @length: The length of number.
 * @width: specification of the width.
 * @flag: specification of flags.
 * @point: character pointing to padding.
 * @ch: Representing extra character.
 * @pointStart: Pointing to indx at which the padding will start.
 *
 * Return: Number of written charaters.
 */
int handlePointer(char buffer[], int indx, int length,
		int width, int flag, char point, char ch, int pointStart)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = point;
		buffer[i] = '\0';
		if (flag & F_MINUS && point == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (ch)
				buffer[--indx] = ch;
			return (write(1, &buffer[indx], length) +
						write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && point == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (ch)
				buffer[--indx] = ch;
			return (write(1, &buffer[3], i - 3) +
					write(1, &buffer[indx], length));
		}
		else if (!(flag & F_MINUS) && point == '0')
		{
			if (ch)
				buffer[--pointStart] = ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pointStart], i - pointStart) +
		write(1, &buffer[indx], length - (1 - pointStart) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';
	if (ch)
		buffer[--indx] = ch;
	return (write(1, &buffer[indx], BUFF_SIZE - indx - 1));
}




/**
 * handleUnsigned - Function that write unsigned number.
 * @negative: To indicate negative number.
 * @indx: Index at which the number will start in the buffer.
 * @buffer: Array of charaters.
 * @flag: Flags specifier.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: size specifier.
 *
 * Return: Tne int in buffer.
 */
int handleUnsigned(int negative, int indx,
		char buffer[], int flag, int width, int precision, int size)
{
	int i = 0;
	char point = ' ';

	int length = BUFF_SIZE - indx - 1;

	UNUSED(negative);
	UNUSED(size);

	if (precision == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		return (0);
	if (precision > 0 && precision < length)
		point = ' ';
	while (precision > length)
	{
		buffer[--indx] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		point = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = point;
		buffer[i] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buffer[indx], length) +
				write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) +
				write(1, &buffer[indx], length));
		}
	}

	return (write(1, &buffer[indx], length));
}
