/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:40:23 by aoner             #+#    #+#             */
/*   Updated: 2022/02/22 16:19:01 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_put_base(unsigned int nbr, const char *base, int *count)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr < base_len)
	{
		*count += ft_putcharp(base[nbr % base_len], 1);
		return ;
	}
	else
	{
		ft_put_base(nbr / base_len, base, count);
		ft_put_base(nbr % base_len, base, count);
	}
}
