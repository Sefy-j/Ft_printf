/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:26:19 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/01/19 12:43:26 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int n, size_t i)
{
	if (n == -2147483648)
	{
		i += ft_putchar('2');
		i = ft_putnbr(147483648, i);
	}
	else if (n < 0)
		i = ft_putnbr(-n, i);
	else if (n > 9)
	{	
		i = ft_putnbr(n / 10, i);
		i = ft_putnbr(n % 10, i);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

size_t	ft_putnbr_base(int nb)
{
	size_t	i;

	i = 0;
	i += ft_putnbr(nb, i);
	return (i);
}

size_t	ft_printnbr(t_format arg, int nb, char exsign)
{
	size_t	i;

	i = 0;
	if (arg.space != 0 && arg.zero == 1 && arg.sign == 0)
		i += ft_putchar(exsign);
	if (arg.sign == 1 && arg.zero == 1)
	{
		i += ft_putchar('-');
		arg.sign--;
	}
	while ((int)i < (int)(arg.width - arg.sign) && arg.width != 0)
		i += ft_putchar(arg.conver);
	if (arg.sign == 1 && arg.zero == 0)
		i += ft_putchar('-');
	while (arg.size < arg.precision + arg.sign)
	{
		i += ft_putchar('0');
		arg.size++;
	}
	if ((arg.space != 0 || arg.plus != 0) && arg.sign == 0)
		i += ft_putchar(exsign);
	if (!(nb == 0 && arg.precision == 0 && arg.point == 1))
		i += ft_putnbr_base(nb);
	return (i);
}

size_t	ft_printnbrdash(t_format arg, int nb, char exsign)
{
	size_t	i;

	i = 0;
	if ((arg.space != 0 || arg.plus != 0) && arg.sign == 0)
		i += ft_putchar(exsign);
	if (arg.sign == 1)
		i += ft_putchar('-');
	while (arg.size < arg.precision)
	{
		i += ft_putchar('0');
		arg.size++;
	}
	if (!(nb == 0 && arg.precision == 0 && arg.point == 1))
		i += ft_putnbr_base(nb);
	while (i < arg.width && arg.width != 0)
		i += ft_putchar(arg.conver);
	return (i);
}

size_t	ft_printnumber(int nb, t_format arg)
{
	size_t	i;
	char	exsign;

	i = 0;
	arg.size = ft_nblen(nb, i);
	arg = ft_checknbrflag(arg, nb, &exsign);
	if (arg.dash != 0)
		i = ft_printnbrdash(arg, nb, exsign);
	else if (arg.dash == 0)
		i = ft_printnbr(arg, nb, exsign);
	return (i);
}
