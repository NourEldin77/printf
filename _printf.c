#include "main.h"

/**
 * _print_char - print char to stdout
 * @c: char to be printed
 * Return: num of bytes
 */

int _print_char(int c)
{
	char x = write(1, &c, 1);

	return (x);
}

/**
 * _print_string - print string with using _print_char to stdout
 * @c: pointer to the first char of string
 * Return: num of bytes
 */

int _print_string(char *c)
{
	int bytes = 0;

	if (c != NULL)
	{
		for (; *c != '\0'; bytes++)
		{
			_print_char((int)*c);
			++c;
		}
	}
	return (bytes);
}

/**
 * _specifier - detrmaine flag after % and how it will print
 * @flag: char % (specifier)
 * @ap: pointer with type va_list that point to printf arguments
 * Return: num of bytes
 */

int _specifier(char flag, va_list ap)
{
	int bytes = 0;

	switch (flag)
	{
		case 'c':
			bytes = _print_char(va_arg(ap, int));
			break;
		case 's':
			bytes = _print_string(va_arg(ap, char *));
			break;
		default:
			bytes += write(1, &flag, 1);
			break;
	}
	return (bytes);
}

/**
 * _printf - Entry point that loop at format pointer until hit % or '\0'
 * @format: const char pointer that take string and specofier to print
 * Return: num of bytes
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int bytes;

	va_start(ap, format);
	bytes = 0;
	if (format == NULL)
	{
		return (-1);
	}
	for ( ; *format != '\0' && format != NULL ; ++format)
	{
		if (*format == '%')
		{
			bytes += _specifier(*(++format), ap);
		}
		else
		{
			bytes += write(1, format, 1);
		}
	}
	va_end(ap);
	return (bytes);
}
