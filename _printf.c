#include "main.h"
/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1..
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @s: The string to print
 *
 * Return: On success the number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puts(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		i++;
	}
	return (i);
}

/**
* print_number - helper function used to print out an int
* @n: the number we want to be printed or putcharred
*
* Description: so i did binary pretty simple but i got large binary int
*	instead of string it in an array i wanted a way to print each digit
* Return: returns the count number! so we can add it to our counter
*/

int print_number(int n)
{
int div;
int count = 0;

for (div = 1; div <= n; div *= 10)
;
while (n > 0)
{
div /= 10;
_putchar(n / div + '0');
n %= div;
count++;
}
return (count);
}
/**
 * handle_specifier - handles the conversion specifier character
 * @specifier: the conversion specifier character
 * @arg_list: the list of arguments to be printed
 * Return: the number of characters printed
 *
 * Description: Determines which conversion function to call based on the
 * conversion specifier character, and passes the corresponding argument(s)
 * from arg_list to that function. Returns the total number of characters
 * printed.
 */
int handle_specifier(char specifier, va_list arg_list)
{
int count = 0;
char *str;
int num;

switch (specifier)
{
case 'c':
count += _putchar(va_arg(arg_list, int));
break;
case 's':
str = va_arg(arg_list, char *);
if (str == NULL)
count += _puts("(null)");
else
count += _puts(str);
break;
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(specifier);
break;
case 'd':
case 'i':
num = va_arg(arg_list, int);
count += print_number(num);
break;
}
return (count);
}

/**
 * _printf - a custom implementation of the printf function
 * @format: a format string containing conversion specifiers
 * Return: the number of characters printed
 *
 * Description: Formats and prints a string to the standard output based on the
 * conversion specifiers found in the format string.
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list arg_list;
int i;

va_start(arg_list, format);

if (format == NULL)
return (-1);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
count += _putchar(format[i]);
else
{
i++;
if (format[i] == '\0')
return (-1);
count += handle_specifier(format[i], arg_list);
}
}

va_end(arg_list);
return (count);
}
