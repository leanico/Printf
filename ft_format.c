/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:58:17 by leaherre          #+#    #+#             */
/*   Updated: 2025/10/31 15:58:17 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_print_char(int c)
{
	int	res;
	int	count;

	count = 0;
	res = write (1, &c, 1);
	if (res == -1)
		return (-1);
	count = res + count;
	return (count);
}

static int	ft_print_unsigned(unsigned int n)
{
	int		res;
	int		count;
	char	*s;
	int		len;

	count = 0;
	len = ft_strlen (s);
	res = write(1, s, len);
	if (res == -1)
		return (-1);
	count = res + count;
	return (count);
}

static int	ft_putstr(char *s)
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

static int	ft_printptr(unsigned long long n)
{
	int	count;
	int	res;

	count = 0;
	res = write (1, "0x", 2);
	if (res == -1)
		return (-1);
	count = count + res;
	res = ft_hex_base(n);
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

static int	ft_hex_base(unsigned long long n)
{
	int	remainder;
	int	count;
	int	res;

	count = 0;
	remainder = n % 16;
	if ((n / 16) > 0)
	{
		res = ft_hex_base (n / 16);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	if (remainder > 9)
		res = ft_putchar(remainder + 'a' - 10);
	else
		res = ft_putchar(remainder + '0');
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

static int	ft_hex_base_up(unsigned long long n)
{
	int	remainder;
	int	count;
	int	res;

	count = 0;
	remainder = n % 16;
	if ((n / 16) > 0)
	{
		res = ft_hex_base_up (n / 16);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	if (remainder > 9)
		res = ft_putchar(remainder + 'A' - 10);
	else
		res = ft_putchar(remainder + '0');
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}
static char	*ft_itoa(int n)
{
	int		len;
	long	copy;
	char	*str;
	int		i;

	copy = n;
	len = ft_strlen(n);
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		copy = -copy;
	str[len] = '\0';
	i = len - 1;
	if (copy == 0)
		str[0] = '0';
	while (copy > 0)
	{
		str[i] = ((copy % 10) + '0');
		copy = copy / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
