#include "main.h"

/**
 * _printf -prints according to a given format. printf Implementation.
 * @format: string holding characters and format of arguments to be printed.
 *
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list original, copy;
	int my_printed = 0, error = 0;

	if (format == NULL || *format == '\0')
		return (0);

	va_start(original, format);
	va_copy(copy, original);

	error = check_input(format, &original);

	if (error != 0)
	{
		return (error *-1);
	}

	my_printed = print_output(format, &copy);

	va_end(original);
	va_end(copy);

	return (my_printed);

}
