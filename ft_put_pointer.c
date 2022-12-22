/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:40:53 by aoner             #+#    #+#             */
/*   Updated: 2022/02/22 15:51:52 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(unsigned long long c, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (c >= 16)
	{
		ft_put_pointer(c / 16, count);
		ft_put_pointer(c % 16, count);
	}
	else
		*count += ft_putcharp(base[c], 1);
}
