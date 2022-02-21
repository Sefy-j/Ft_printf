/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:43:36 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/01/19 12:44:50 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunbr(unsigned int n, size_t i)
{
	if (n > 9)
	{	
		i = ft_putunbr(n / 10, i);
		i = ft_putunbr(n % 10, i);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

size_t	ft_putunbr_base(int nb)
{
	size_t	i;

	i = 0;
	i += ft_putunbr(nb, i);
	return (i);
}

size_t	ft_printunbr(t_format arg, unsigned int nb)
{
	size_t	i;

	i = 0;
	if (arg.space != 0 && arg.zero == 1)
		i += ft_putstr(" ", 2, 0);
	while ((int)i < (int)(arg.width) && arg.width != 0)
		i += ft_putchar(arg.conver);
	while (arg.size < arg.precision)
	{
		i += ft_putchar('0');
		arg.size++;
	}
	if (arg.space != 0 && arg.zero == 0)
		i += ft_putstr(" ", 2, 0);
	if (!(nb == 0 && arg.precision == 0 && arg.point == 1))
		i += ft_putunbr_base(nb);
	return (i);
}

size_t	ft_printunbrdash(t_format arg, unsigned int nb)
{
	size_t	i;

	i = 0;
	if (arg.space != 0)
		i += ft_putstr(" ", 2, 0);
	while (arg.size < arg.precision)
	{
		i += ft_putchar('0');
		arg.size++;
	}
	if (!(nb == 0 && arg.precision == 0 && arg.point == 1))
		i += ft_putunbr_base(nb);
	while (i < arg.width && arg.width != 0)
		i += ft_putchar(arg.conver);
	return (i);
}

size_t	ft_printunsigned(unsigned int nb, t_format arg)
{
	size_t	i;

	i = 0;
	arg.size = ft_nblenu(nb, i);
	arg = ft_checkunbrflag(arg, nb);
	if (arg.dash != 0)
		i = ft_printunbrdash(arg, nb);
	else if (arg.dash == 0)
		i = ft_printunbr(arg, nb);
	return (i);
}
