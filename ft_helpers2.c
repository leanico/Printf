/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:34:35 by leaherre          #+#    #+#             */
/*   Updated: 2025/11/08 17:34:35 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case_xlow(va_list list)
{
	int				res;
	unsigned int	n2;

	n2 = va_arg(list, unsigned int);
	res = ft_hex_base(n2);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_case_xup(va_list list)
{
	int				res;
	unsigned int	n2;

	n2 = va_arg(list, unsigned int);
	res = ft_hex_base_up(n2);
	if (res == -1)
		return (-1);
	return (res);
}
