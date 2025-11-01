# ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

int	ft_printf(char const *format, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
size_t	ft_strlen(const char *str);
int	ft_print_char(int c);
int	ft_print_unsigned(unsigned int n);
int	ft_putstr(char *s);
int	ft_printptr(unsigned long long n);
int	ft_hex_base(unsigned long long n);
int	ft_hex_base_up(unsigned long long n);

#endif
//// chequear bien que esten todas lpm

/// deberian ser todas static no? static va solo en las funciones pero en .h no no?