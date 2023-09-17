#include "main.h"
/**
 * _print_num_int - print integers decimals hexadec to stdout
 * @num: long int num
 * @base: base 16 or 10 or 8
 * @sign: lower or upper case hex
 * Return: num of bytes
*/

int _print_num_int(long int num, int base, int sign)
{
	char *ptr = sign ? "0123456789ABCDEF" : "0123456789abcdef";
	int bytes = 0;

		if (num < 0)
		{
			_print_char('-');
			return (_print_num_int (-num, base, sign) + 1);
		}
		else if (num < base)
		{
			return (_print_char(ptr[num]));
		}
		else
		{
			bytes = _print_num_int(num / base, base, sign);
			return (bytes + _print_num_int (num % base, base, sign));
		}
}
