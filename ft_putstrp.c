/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:41:29 by aoner             #+#    #+#             */
/*   Updated: 2022/02/22 16:16:26 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrp(const char *str, int fd)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
	{
		count += ft_putstrp("(null)", fd);
		return (count);
	}
	while (str[i])
	{
		count += write(fd, &str[i], 1);
		i++;
	}
	return (count);
}
