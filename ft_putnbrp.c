/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:41:20 by aoner             #+#    #+#             */
/*   Updated: 2022/02/22 15:41:21 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrp(int c, int *count)
{
	long int	k;

	k = c;
	if (k < 0)
	{
		*count += write(1, "-", 1);
		k *= -1;
	}
	if (k > 9)
	{
		ft_putnbrp(k / 10, count);
		ft_putnbrp(k % 10, count);
	}
	else
		*count += ft_putcharp(k + 48, 1);
}
