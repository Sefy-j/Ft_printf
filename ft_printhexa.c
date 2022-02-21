/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:43:51 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/01/19 12:42:52 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putx(unsigned int n, unsigned int l, char *b, size_t i)
{
	if (n > l - 1)
	{	
		i = ft_putx(n / l, l, b, i);
		i = ft_putx(n % l, l, b, i);
	}
	else
		i += ft_putchar(b[n]);
	return (i);
}

size_t	ft_putx_base(unsigned int nb, char *b)
{
	size_t	i;

	i = 0;
	i += ft_putx(nb, ft_strlen(b), b, i);
	return (i);
}

size_t	ft_printx(t_format arg, char *base, unsigned int nb, char *dirx)
{
	size_t	i;

	i = 0;
	if (arg.pad != 0 && arg.zero == 1)
		i += ft_putstr(dirx, 2, 0);
	while ((int)i < (int)(arg.width - arg.precision) && arg.width != 0)
		i += ft_putchar(arg.conver);
	while (arg.size < arg.precision + arg.sign)
	{
		i += ft_putchar('0');
		arg.size++;
	}
	if (arg.pad != 0 && arg.zero == 0)
		i += ft_putstr(dirx, 2, 0);
	if (!(nb == 0 && arg.precision == 0 && arg.point == 1))
		i += ft_putx_base(nb, base);
	return (i);
}

size_t	ft_printxdash(t_format arg, char *base, unsigned int nb, char *dirx)
{
	size_t	i;

	i = 0;
	while (arg.size < arg.precision + arg.sign)
	{
		i += ft_putchar('0');
		arg.size++;
	}
	if (arg.pad != 0)
		i += ft_putstr(dirx, 2, 0);
	if (!(nb == 0 && arg.precision == 0 && arg.point == 1))
		i += ft_putx_base(nb, base);
	while (i < arg.width && arg.width != 0)
		i += ft_putchar(arg.conver);
	return (i);
}

size_t	ft_printhexa(unsigned int nb, t_format arg)
{
	size_t	i;
	char	*base;
	char	*dirx;

	i = 0;
	if (arg.conver == 'x')
	{
		base = HEXALW;
		dirx = DIRLW;
	}
	else
	{
		base = HEXAUP;
		dirx = DIRUP;
	}
	arg.size = ft_nblenx(nb, ft_strlen(base), base, arg.size);
	arg = ft_checkflagx(arg, nb);
	if (arg.dash != 0)
		i = ft_printxdash(arg, base, nb, dirx);
	else if (arg.dash == 0)
		i = ft_printx(arg, base, nb, dirx);
	return (i);
}
