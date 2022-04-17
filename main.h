#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct structprint - structure containing
 * @q: the location and method to translate data to characters.
 * @u: print function for specific type.
 *
 * Return: int 
 */
typedef struct structprint
{
	char *q;
	int (*u)(char *format, va_list);
} structype;
int _putchar(char ch);
int _printf(char *format, ...);
#endif
