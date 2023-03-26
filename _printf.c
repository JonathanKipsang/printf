#include "main.h"
/**
 * _printf - prints a name
 * _putchar - prints a char c
 * @format: string containing the name to print
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = (char)va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*format == 's')
{
char *s = va_arg(args, char*);
int len = 0;
while (s[len] != '\0')
len++;
write(1, s, len);
count += len;
}
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
}
else
{
write(1, format, 1);
count++;
}
format++;
}
va_end(args);
return (count);
}
