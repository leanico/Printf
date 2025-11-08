/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:34:40 by leaherre          #+#    #+#             */
/*   Updated: 2025/11/08 17:34:40 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	int		len;
	long	copy;
	char	*str;
	int		i;

	copy = n;
	len = ft_numlen(n);
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
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
	return (str);
}

int	ft_numlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}
