#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
<<<<<<< HEAD

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
=======
	return (i);
}


/**
 * print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: The number of digits printed
 */
int print_number(int n)
{
int count = 0;

if (n < 0)
{
_putchar('-');
count++;
n = -n;
}

if (n / 10)
{
count += print_number(n / 10);
}

_putchar((n % 10) + '0');
count++;

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
case 'd':
case 'i':
num = va_arg(arg_list, int);
count += print_number(num);
break;
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(specifier);
break;
}
return (count);
>>>>>>> 03b262eee7358e801917af6e41cc201c534e4fe4
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

