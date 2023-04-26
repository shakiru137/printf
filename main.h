#ifndef MAIN_H 
#define MAIN_H 
#include <stdarg.h> 
#include <stdio.h> 
#include <unistd.h> 
#define UNUSED(x) (void)(x) 
#define BUFF_SIZE 1024 
/* FLAGS */ 
#define F_MINUS 1 
#define F_PLUS 2 
#define F_ZERO 4 
#define F_HASH 8 
#define F_SPACE 16 
/* SIZES */ 
#define S_LONG 2 
#define S_SHORT 1 
/** 
* struct fmt - Struct op 
* 
* @fmt: The format. 
* @k: The function associated. 
*/ 
struct fmt 
{ 
char fmt; 
int (*k)(va_list, char[], int, int, int, int); }; 
/** 
* typedef struct fmt formatType - Struct op * 
* @fmt: The format. 
* @fm_t: The function associated. 
*/
typedef struct fmt formatType; 
int _printf(const char *format, ...); 
int aug_type(const char *fmt, int *i, 
va_list list, char buffer[], int flags, int width, int precision, int size); /****************** FUNCTIONS ******************/ 
/* Funtions to print chars and strings */ 
int chars(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int strings(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int percents(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
/* Functions to print numbers */ 
int type_int(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int type_binary(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int type_unsigned(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int type_octal(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int type_hexadecimal(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int type_hexa_upper(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
int type_hexa(va_list types, char map_to[], 
char buffer[], int flags, char flag_ch, int width, int precision, int size); 
/* Function to print non printable characters */ 
int nonPrint(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
/* Funcion to print memory address */ 
int memory(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
/* Funciotns to handle other specifiers */ 
int g_flags(const char *format, int *i); 
int g_width(const char *format, int *i, va_list list);
int g_precision(const char *format, int *i, va_list list);
int g_size(const char *format, int *i); 
/*Function to print string in reverse*/ 
int reverse(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
/*Function to print a string in rot 13*/ 
int rot13string(va_list types, char buffer[], 
int flags, int width, int precision, int size); 
/* width handler */ 
int handleChar(char c, char buffer[],
int flags, int width, int precision, int size); 
int handleNumber(int is_positive, int ind, char buffer[], int flags,
		int width, int precision, int size); 
int handleNum(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c); 
int handlePointer(char buffer[], int ind, int length, 
int width, int flags, char padd, char extra_c, int padd_start); 
int handleUnsigned(int is_negative, int ind, 
char buffer[], 
int flags, int width, int precision, int size); 
/****************** UTILS ******************/ 
int printable(char); 
int hexaCode(char, char[], int); 
int dig(char); 
long int numberConv(long int num, int size);
long int unsignedConv(unsigned long int num, int size); 
#endif /* MAIN_H */

