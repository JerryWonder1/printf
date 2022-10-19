#ifndef FUNC
#define FUNC

#include <stdarg.h>
#include <unistd.h>

int _putchar(char x);
int print_newline(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_num(int num);
int print_base2(va_list args);
int print_in_base(unsigned int num, unsigned int base);
int _printf(const char *format, ...);
int print_special_char(char *next_character, va_list args);
int print_substitution(char *character, char *next_character, va_list args);

typedef struct print_map {
	char *s;
	int (*f)(va_list args);
} function_map;

#endif
