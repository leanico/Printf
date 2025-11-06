/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:58:15 by leaherre          #+#    #+#             */
/*   Updated: 2025/10/31 15:58:15 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_rec(long nb)
{
	int	count;
	int	res;

	count = 0;
	if (nb >= 10)
	{
		res = ft_putnbr_rec(nb / 10);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	res = ft_putchar(nb % 10 + '0');
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		res;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		res = write(1, "-", 1);
		if (res == -1)
			return (-1);
		count = count + res;
		nb = -nb;
	}
	res = ft_putnbr_rec(nb);
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

int	ft_putchar(char c)
{
	int	res;

	res = write(1, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str [i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	res;
	int	count;

	count = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	res = write (1, s, ft_strlen(s));
	if (res == -1)
		return (-1);
	count = res + count;
	return (count);
}
