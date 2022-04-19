#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} c_flags;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, c_flags *f);
} ph;

/* print_nums */
int print_int(va_list l, c_flags *f);
void print_number(int n);
int print_unsigned(va_list l, c_flags *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, c_flags *f);
int print_hex_big(va_list l, c_flags *f);
int print_binary(va_list l, c_flags *f);
int print_octal(va_list l, c_flags *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, c_flags *);

/* get_flag */
int get_flag(char s, c_flags *f);

/* print_alpha */
int print_string(va_list l, c_flags *f);
int print_char(va_list l, c_flags *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, c_flags *f);
int print_rev(va_list l, c_flags *f);
int print_bigS(va_list l, c_flags *f);

/* print_address */
int print_address(va_list l, c_flags *f);

/* print_percent */
int print_percent(va_list l, c_flags *f);

#endif
