#include "main.h"

/**
 * _printf -prints according to a given format. printf Implementation.
 * @format: string holding characters and format of arguments to be printed.
 *
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	int my_print = 0, (*structype)(char *, va_list);
	char q[3];
	va_list pa;

	if (format == NULL)
		return (-1);
	q[2] = '\0';
	va_start(pa, format);
	_putchar(-1);
	while (format[0])
	{
		if (format[0] == '%')
		{
			structype = driver(format);
			if (structype)
			{
				q[0] = '%';
				q[1] = format[1];
				my_print += structype(q, pa);
			}
			else if (format[1] != '\0')
			{
				my_print += _putchar('%');
				my_print += _putchar(format[1]);
			}
			else
			{
				my_print += _putchar('%');
				break; 
			}
			format += 2;
		}
		else
		{
			my_print += _putchar(format[0]);
			format++;
		}
	}
	_putchar(-2);
	return (my_print);

}
