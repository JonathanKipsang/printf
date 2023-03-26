#include "main.h"
/**
 * _printf - prints a name
 * @format: string containing the name to print
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
count += puts(va_arg(args, char *));
break;
case '%':
count += putchar('%');
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
