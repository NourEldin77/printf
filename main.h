#ifndef _HEAD_
#define _HEAD_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _print_hex_string(char *str);
int _print_rot13(const char *str);
int _print_bin(unsigned int value);
int _printf(const char *format, ...);
int _print_char (int c);
int _print_string(char *c);
int _specifier(char flag, va_list ap);
int _print_num_int (long int num, int base, int sign);
int _print_string_rev(char *c);
int _strlen(char *s);

#endif
