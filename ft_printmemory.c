/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:43:51 by jlopez-f          #+#    #+#             */
/*   Updated: 2021/12/15 17:54:52 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putp(unsigned long long n, unsigned long long l, char *b, size_t i)
{
	if (n > l - 1)
	{	
		i = ft_putp(n / l, l, b, i);
		i = ft_putp(n % l, l, b, i);
	}
	else
		i += ft_putchar(b[n]);
	return (i);
}

size_t	ft_putp_base(unsigned long long int nb, char *base)
{
	size_t	i;

	i = 0;
	i += ft_putp(nb, ft_strlen(base), base, i);
	return (i);
}

size_t	ft_printp(t_format arg, char *base, unsigned long long nb)
{
	size_t	i;

	i = 0;
	if (arg.dash != 0)
	{
		if (arg.pad != 0)
			i += ft_putstr(DIRLW, 2, 0);
		i += ft_putp_base(nb, base);
		while (i < arg.width && arg.width != 0)
			i += ft_putchar(arg.conver);
	}	
	else if (arg.dash == 0)
	{
		if (arg.pad != 0 && arg.zero == 1)
			i += ft_putstr(DIRLW, 2, 0);
		while ((int)i < (int)(arg.width - arg.precision) && arg.width != 0)
			i += ft_putchar(arg.conver);
		if (arg.pad != 0 && arg.zero == 0)
			i += ft_putstr(DIRLW, 2, 0);
		i += ft_putp_base(nb, base);
	}
	return (i);
}

size_t	ft_printmemory(unsigned long long int nb, t_format arg)
{
	size_t	i;
	char	*base;

	i = 0;
	base = HEXALW;
	arg.size = ft_nblenp(nb, ft_strlen(base), base, arg.size);
	arg = ft_checkflagp(arg);
	i = ft_printp(arg, base, nb);
	return (i);
}
