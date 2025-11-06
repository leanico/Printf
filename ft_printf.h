/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:02:05 by marvin            #+#    #+#             */
/*   Updated: 2025/11/05 21:02:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

int		ft_printf(char const *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_print_char(int c);
int		ft_print_unsigned(unsigned int n);
int		ft_putstr(char *s);
int		ft_printptr(unsigned long long n);
int		ft_hex_base(unsigned long long n);
int		ft_hex_base_up(unsigned long long n);
char	*ft_uitoa(unsigned int n);
size_t	ft_strlen(const char *str);
int		ft_numlen(unsigned int n);
int		ft_case_c(va_list list);
int		ft_case_s(va_list list);
int		ft_case_di(va_list list);
int		ft_case_u(va_list list);
int		ft_case_p(va_list list);
int		ft_case_x(va_list list);
int		ft_case_x2(va_list list);
int		ft_printf_aux(char c, va_list list);

#endif
