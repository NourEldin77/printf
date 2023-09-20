#include "main.h"
/**
 * _print_hex_string - print hex string
 * @str: pointer to char
 * Return: bytes
*/
int _print_hex_string(char *str)
{
int bytes = 0;

	if (str == NULL)
	{
		return (_print_string("(null)"));
	}

	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			bytes += _print_char('\\');
			bytes += _print_char('x');
			bytes += _print_char('0');
			bytes += _print_num_int(*str, 16, 1);
		}
		else
		{
			bytes += _print_char(*str);
		}
		str++;
	}

	return (bytes);
}
/**
 * _print_rot13 - prints rot13 in scrambled unreadable way
 * @str: char pointer
 * Return: rot
*/
int _print_rot13(const char *str)
{
	int rot = 0;
	char base;

	while (*str)
		{
		char c = *str;

		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			{
			base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
			_print_char((((c - base + 13) % 26) + base));
			rot++;
		}
	else
		{
			_print_char(c);
			rot++;
		}
		str++;
	}
	return (rot);
}
