/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:05:49 by jlopez-f          #+#    #+#             */
/*   Updated: 2021/12/15 19:53:19 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	ft_checknbrflag(t_format arg, int nb, char *exsign)
{
	if (nb < 0)
		arg.sign = 1;
	if (arg.point != 0 || arg.dash != 0)
		arg.zero = 0;
	if (arg.dash == 0 && arg.width != 0)
	{
		if (!(arg.precision == 0 && nb == 0 && arg.point == 1))
		{
			if (arg.precision < arg.size)
				arg.width += arg.sign - arg.size;
			else
				arg.width -= arg.precision;
		}
	}
	if (arg.zero == 0)
		arg.conver = ' ';
	if (arg.zero == 1)
		arg.conver = '0';
	if (arg.plus == 1)
		*exsign = '+';
	else if (arg.space == 1)
		*exsign = ' ';
	if (arg.sign == 1 && arg.precision != 0 && arg.dash == 1)
		arg.precision++;
	return (arg);
}

t_format	ft_checkunbrflag(t_format arg, unsigned int nb)
{
	if (arg.point != 0 || arg.dash != 0)
		arg.zero = 0;
	if (arg.dash == 0 && arg.width != 0)
	{
		if (!(arg.precision == 0 && nb == 0 && arg.point == 1))
		{
			if (arg.precision <= arg.size)
				arg.width -= arg.size;
			else
				arg.width -= arg.precision;
		}
	}
	if (arg.zero == 0)
		arg.conver = ' ';
	if (arg.zero == 1)
		arg.conver = '0';
	return (arg);
}

t_format	ft_checkflagx(t_format arg, unsigned int nb)
{
	if (arg.point != 0 || arg.dash != 0)
		arg.zero = 0;
	if (nb == 0)
		arg.pad = 0;
	if (arg.precision <= arg.size && \
	!(arg.precision == 0 && arg.point == 1 && nb == 0))
		arg.precision = arg.size;
	if (arg.zero == 0)
		arg.conver = ' ';
	if (arg.zero == 1)
		arg.conver = '0';
	return (arg);
}

t_format	ft_checkflagp(t_format arg)
{
	arg.pad = 1;
	if (arg.point != 0 || arg.dash != 0)
		arg.zero = 0;
	if (arg.precision < arg.size)
		arg.precision = arg.size;
	if (arg.zero == 0)
	{
		arg.conver = ' ';
		if (arg.dash == 0)
			arg.width -= 2;
	}
	if (arg.zero == 1)
		arg.conver = '0';
	return (arg);
}
