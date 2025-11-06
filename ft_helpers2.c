/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:13:14 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 20:13:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case_x(va_list list)
{
	int				res;
	unsigned int	n2;

	n2 = va_arg(list, unsigned int);
	res = ft_hex_base(n2);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_case_x2(va_list list)
{
	int				res;
	unsigned int	n2;

	n2 = va_arg(list, unsigned int);
	res = ft_hex_base_up(n2);
	if (res == -1)
		return (-1);
	return (res);
}
