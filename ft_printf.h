/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:32:20 by aoner             #+#    #+#             */
/*   Updated: 2022/02/22 15:37:06 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_put_base(unsigned int nbr, const char *base, int *count);
void	ft_put_pointer(unsigned long long c, int *count);
int		ft_putcharp(char c, int fd);
void	ft_putnbrp(int c, int *count);
int		ft_putstrp(const char *str, int fd);

#endif
