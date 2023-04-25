#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define HASH_FLAG 0x10
#define JUST_FLAG 0x8
#define PLUS_FLAG 0x4
#define SPACE_FLAG 0x2
#define ZERO_FLAG 0x1
#define BUF_SIZE 1024

/**
 * struct spec - Struct to hold format info for string conversion functions
 * @flags: small integer used as a bitfield to store flags from format string
 * @length: `l' of `\0' depending on whether `long' is found in length field
 * @width: minimum number of characters to output +/- padding
 * @prec: precision to print for floats, or bytes to print from string
 * @stride: total amount of format info "digested" by format parser
 * @func: function to use for printing next argument from `va_list'
 */
struct spec
{
	char flags;
	char length;
	int width;
	int prec;
	int stride;
	int (*func)(struct spec *, va_list);
};
/**
 * spec_t - typedef for struct `spec'
 */
typedef struct spec spec_t;
/**
 * struct conv_func - struct to hold format specifier symbol and
 * associated string conversion function.
 * @symbol: format string symbol (e.g. `s' or `d')
 * @func: function to convert specified argument type
 */
struct conv_func
{
	char symbol;
	int (*func)(spec_t *, va_list);
};
/**
 * conv_func_t - typedef for struct `conv_func'
 */
typedef struct conv_func conv_func_t;
void get_spec(const char *, spec_t *);
int setflags(const char *, spec_t *);
int setwidth(const char *, spec_t *);
int setprec(const char *, spec_t *);
int setlength(const char *, spec_t *);
int settype(const char *, spec_t *);
int conv_pc(spec_t *, va_list);
int conv_i(spec_t *, va_list);
int conv_u(spec_t *, va_list);
int conv_b(spec_t *, va_list);
int conv_f(spec_t *, va_list);
int conv_e(spec_t *, va_list);
int conv_E(spec_t *, va_list);
int conv_x(spec_t *, va_list);
int conv_X(spec_t *, va_list);
int conv_o(spec_t *, va_list);
int conv_s(spec_t *, va_list);
int conv_S(spec_t *, va_list);
int conv_c(spec_t *, va_list);
int conv_p(spec_t *, va_list);
int conv_a(spec_t *, va_list);
int conv_A(spec_t *, va_list);
int conv_r(spec_t *, va_list);
int _isdigit(char);
int write_hex(unsigned char);
int isprintable(unsigned char);
int _printf(const char *format, ...);
unsigned int writetobuf(char *, unsigned int);
int conv_base(char *, int, unsigned long int, ...);
#endif /* _MAIN_H_ */
