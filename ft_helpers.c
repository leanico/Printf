/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:34:23 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 19:34:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case_c(va_list list)
{
	int	res;
	int	c;

	c = va_arg(list, int);
	res = ft_print_char(c);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_case_s(va_list list)
{
	char	*s;
	int		res;

	s = va_arg(list, char *);
	res = ft_putstr(s);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_case_di(va_list list)
{
	int	n;
	int	res;

	n = va_arg(list, int);
	res = ft_putnbr(n);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_case_p(va_list list)
{
	void	*p;
	int		res;

	p = va_arg(list, void *);
	res = ft_printptr((unsigned long long)p);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_case_u(va_list list)
{
	unsigned int	n2;
	int				res;

	n2 = va_arg(list, unsigned int);
	res = ft_print_unsigned(n2);
	if (res == -1)
		return (-1);
	return (res);
}
