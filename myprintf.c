#include "main.h"

extern char buf[BUF_SIZE];
extern unsigned int buf_idx;

/**
 * _printf - print formatted string to stdout using variable number
 * of arguments
 * @format: format string to specify how to interpret unnamed arguments
 *
 * Return: number of bytes printed to stdout
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char c;
	int n, i;
	spec_t spec;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	for (i = 0; (c = format[i]); ++i)
	{
		if (c != '%')
			writetobuf(&c, 1);
		else
		{
			get_spec(format + i + 1, &spec);
			if (spec.func == NULL)
			{
				if (format[i + spec.stride] == '\0')
					break;
				writetobuf(&c, 1);
				continue;

			}
			spec.func(&spec, ap);
			i += spec.stride;
		}
	}
	n = 0;
	n = write(1, buf, buf_idx);
	buf_idx = 0;
	buf[buf_idx] = '\0';
	va_end(ap);
	return (n);
}
