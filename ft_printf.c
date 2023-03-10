/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:17:20 by aoner             #+#    #+#             */
/*   Updated: 2022/02/20 20:03:15 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(char c, va_list argmn)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putcharp(va_arg(argmn, int), 1);
	if (c == 's')
		count += ft_putstrp(va_arg(argmn, char *), 1);
	if (c == 'd' || c == 'i')
		ft_putnbrp(va_arg(argmn, int), &count);
	if (c == 'p')
	{
		count += write(1, "0x", 2);
		ft_put_pointer(va_arg(argmn, unsigned long long), &count);
	}
	if (c == 'u')
		ft_put_base(va_arg(argmn, unsigned int), "0123456789", &count);
	if (c == 'x')
	{
		ft_put_base(va_arg(argmn, unsigned int), "0123456789abcdef", &count);
	}
	if (c == 'X')
		ft_put_base(va_arg(argmn, unsigned int), "0123456789ABCDEF", &count);
	if (c == '%')
		count += ft_putcharp('%', 1);
	return (count);
}

static int	check_str(const char *str, va_list argmn)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i ++;
			while (str[i] == ' ')
				i++;
			if (!str[i])
				return (count);
			count += find_format(str[i], argmn);
		}
		else
			count += ft_putcharp(str[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	argmn;
	int		count;

	count = 0;
	va_start(argmn, str);
	count += check_str(str, argmn);
	va_end(argmn);
	return (count);
}
