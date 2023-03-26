#include "main.h"
/**
 * print_char - prints a single character to the standard output
 * @c: A character to print
 * Return: The number of characters printed (always 1)
 */
int print_char(char c)
{
return (write(1, &c, 1));
}

/**
 * print_str - Prints a string to the standard output
 * @arg: A va_list containing the string to print
 * Return: The number of characters printed..
*/
int print_str(va_list arg)
{
char *s = va_arg(arg, char *);
int len = 0;

if (s == NULL)
{
write(1, "(null)", 6);
return (6);
}
while (s[len])
len++;
write(1, s, len);
return (len);
}

/**
 * print_percent - prints a percent character to the standard output
 * @arg: A va_list containing no arguments (unused)
 * Return: The number of characters printed (always 1)
*/
int print_percent(va_list arg)
{
(void)arg;
write(1, "%", 1);
return (1);
}

/**
 * _printf - Custom printf function that supports %c, %s, and %%
 * @format: A format string containing zero or more directives
 * Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
va_list arg;
int i, len = 0;
va_start(arg, format);

if (format == NULL)
return (-1);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
write(1, &format[i], 1);
len++;
continue;
}

switch (format[++i])
{
case 'c':
len += print_char(arg);
break;

case 's':
len += print_str(arg);
break;

case '%':
len += print_percent(arg);
break;

default:
write(1, "%", 1);
write(1, &format[i], 1);
len += 2;
break;
}
}
va_end(arg);
return (len);
}
