#include "main.h"

/**
 * _print_char - print char to stdout
 * @c: char to be printed
 * Return: num of bytes
 */

int _print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - print string with using _print_char to stdout
 * @c: pointer to the first char of string
 * Return: num of bytes
 */

int _print_string(char *c)
{
	int bytes = 0;
	int i = 0;

		if (c == NULL)
		{
			return (_print_string("(null)"));
		}
		for (; *c != '\0'; i++)
		{
			bytes += _print_char((int)*c);
			++c;
		}
	return (bytes);
}

/**
 * _print_string_rev - print string in reverse using strlen as helper
 * @c: pointer to the first char of string
 * Return: num of bytes
 */

int _print_string_rev(char *c)
{
	int bytes = 0;
	int len = _strlen(c);
	int x = len - 1;

	if (c == NULL)
	{
		return (_print_string("(null)"));
	}
	while (x >= 0)
	{
		bytes += _print_char((int)c[x]);
		x--;
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
		case 'd':
		case 'i':
			bytes = _print_num_int((long)va_arg(ap, int), 10, 0);
			break;
		case 'u':
			bytes = _print_num_int((unsigned long)va_arg(ap, unsigned int), 10, 0);
			break;
		case 'x':
			bytes = _print_num_int((long)va_arg(ap, unsigned int), 16, 0);
			break;
		case 'X':
			bytes = _print_num_int((long)va_arg(ap, unsigned int), 16, 1);
			break;
		case 'o':
			bytes = _print_num_int((long)va_arg(ap, unsigned int), 8, 0);
			break;
		case 'b':
			bytes = _print_bin((long)va_arg(ap, unsigned long int));
			break;
		case 'R':
			bytes = _print_rot13(va_arg(ap, const char *));
			break;
		case 'r':
			bytes = _print_string_rev(va_arg(ap, char *));
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
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
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
