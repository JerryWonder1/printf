#ifndef FUNC
#define FUNC

#include <stdarg.h>
#include <unistd.h>

#define BUFFSIZE 1024

int _putchar(char x);
int print_newline(va_list args, char *buffer);
int print_char(va_list args, char *buffer);
int print_string(va_list args, char *buffer);
int print_int(va_list args, char *buffer);
int print_num(long int num, char *buffer);
int print_base2(va_list args, char *buffer);
int print_base8(va_list args, char *buffer);
int print_base10(va_list args, char *buffer);
int print_in_base(unsigned long int num, unsigned int base, char *caps, char *buffer);
char substitute_number(int num, char *caps);
int print_in_basex(va_list args, char *buffer);
int print_in_baseX(va_list args, char *buffer);
int _printf(const char *format, ...);
int print_special_char(char *next_character, va_list args, char *buffer);
int print_substitution(char *character, char *next_character, va_list args, char *buffer);
int make_substitution(char *character, char *next_character, va_list args, char *buffer);
void add_to_buffer(char x, char *buffer);
size_t buffsize(char *buffer);
int print_buffer(char *buffer);
void initialize_buffer(char *buffer);
size_t cleanup(char *buffer, va_list args);

typedef struct print_map
{
	char *s;
	int (*f)(va_list args, char *buffer);
} function_map;

#endif
