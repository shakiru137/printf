#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* Defining the flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/* Defing the sizes */
#define S_LONG 2
#define S_SHORT 1
struct fmt
{
	char fmt;
	int (*k)(va_list, char[], int, int, int, int);
};
typedef struct fmt formatType;
int _printf(const char *format, ...);
int aug_type(const char *fmt, int *i,
va_list list, char buffer[], int flag, int width, int precision, int size);
int chars(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int strings(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int percents(va_list types, char buffer[],
	int flag, int width, int precision, int size;
/*
 *  A function to print the  non printable characters
 */
int nonPrint(va_list types, char buffer[],
	int flag, int width, int precision, int size);
/*
 *  A funcion to print the memory addresses
 */
int memory(va_list types, char buffer[],
	int flag, int width, int precision, int size);
/*
 *  The functions to print numbers types
 */
int type_int(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int type_binary(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int type_unsigned(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int type_octal(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int type_hexadecimal(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int type_hexa_upper(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int type_hexa(va_list types, char map_to[], char buffer[], int flag,
	char flagCharacter, int width, int precision, int size);
/* The  funcions to handle the  specifiers */
int flags(const char *format, int *i);
int width(const char *format, int *i, va_list list);
int precision(const char *format, int *i, va_list list);
int size(const char *format, int *i);
/*
 *  The function to print out a string in reverse
 */
int reverse(va_list types, char buffer[],
	int flag, int width, int precision, int size);
/*
 *  Function to print the rot 13 string
 */
int rot13string(va_list types, char buffer[],
	int flag, int width, int precision, int size);
/*
 *The functions to handle the width
 */
int handleChar(char c, char buffer[],
	int flag, int width, int precision, int size);
int handleNumber(int positive, int index, char buffer[],
	int flag, int width, int precision, int size);
int handleNum(int index, char orr[], int flag, int width, int precision,
	int length, char d, char ch);
int handlePointer(char buffer[], int index, int length,
	int width, int flag, char point, char ch, int pointStart);

int handleUnsigned(int negative, int index,
char buffer[], int flag, int width, int precision, int size);

int printable(char);
int hexaCode(char, char[], int);
int dig(char);

long int numberConv(long int num, int size);
long int unsignedConv(unsigned long int num, int size);
#endif
