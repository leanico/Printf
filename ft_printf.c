/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:58:17 by leaherre          #+#    #+#             */
/*   Updated: 2025/10/31 15:58:17 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(char const *format, ...)
{
	va_list			list;
	int				count;
	int				res;
	int				c;
	int				n;
	unsigned int	n2;
	void			*p;
	char			*s;

	count = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(list, int);
				res = ft_print_char(c);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == '%')
			{
				res = write (1, "%", 1);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 's')
			{
				s = va_arg(list, char *);
				res = ft_putstr(s);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'd' || *format == 'i')
			{
				n = va_arg(list, int);
				res = ft_putnbr(n);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'u')
			{
				n2 = va_arg(list, unsigned int);
				res = ft_putnbr(n2);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'p')
			{
				p = va_arg(list, void *);
				res = ft_printptr((unsigned long long)p);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'x')
			{
				n2 = va_arg(list, unsigned int);
				res = ft_hex_base(n2);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'X')
			{
				n2 = va_arg(list, unsigned int);
				res = ft_hex_base_up(n2);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else
			{
				res = write(1, format, 1);
				if (res == -1)
					return (-1);
				count = count + res;
				format++;
			}
			format++;
		}
	}
	va_end(list);
	return (count);
}
