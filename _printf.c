#include "main.h"
/**
 * _putchar - prints a single character to the standard output
 * @c: A character to print
 * Return: The number of characters printed (always 1)
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
* print_char - Prints a char to stdout
* @arg: va_list argument with the char to be printed
*
* Return: The number of characters printed (always 1)
*/
int print_char(va_list arg)
{
char c = va_arg(arg, int);
_putchar(c);
return (1);
}

/**
* print_str - Prints a string to stdout
* @arg: va_list argument with the string to be printed
*
* Return: The number of characters printed (excluding null byte)
*/
int print_str(va_list arg)
{
char *str = va_arg(arg, char*);
int count = 0;

if (!str)
str = "(null)";
while (*str)
{
_putchar(*str++);
count++;
}
return (count);
}

/**
* print_percent - Prints a percent sign to stdout
* @arg: Unused
*
* Return: Always returns 1 (the number of characters printed)
*/
int print_percent(va_list arg __attribute__((unused)))
{
_putchar('%');
return (1);
}

/**
* _printf - Our own printf function
* @format: A character string, composed of zero or more directives
*
* Description: Writes a formatted string to the standard output
* Return: An integer. The number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

va_start(args, format);

while (format && *format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_str(args);
break;
case '%':
count += print_percent(args);
break;
default:
_putchar('%');
_putchar(*format);
count += 2;
break;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
