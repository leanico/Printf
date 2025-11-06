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

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list			list;
	int				count;
	int				res;

	count = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				res = ft_case_c(list);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == '%')
			{
				res = write(1, "%", 1);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 's')
			{
				res = ft_case_s(list);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 'd' || *format == 'i')
			{
				res = ft_case_di(list);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 'u')
			{
				res = ft_case_u(list);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 'p')
			{
				res = ft_case_p(list);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 'x')
			{
				res = ft_case_x(list);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 'X')
			{
				res = ft_case_x2(list);
				if (res == -1)
					return (-1);
				count = res + count;
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
		else
		{
			res = write(1, format, 1);
			if (res == -1)
				return (-1);
			count = count + res;
			format++;
		}
	}
	va_end(list);
	return (count);
}
