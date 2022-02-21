/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:13:43 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/01/19 12:44:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s, ssize_t size, size_t point)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	if (size != 0)
	{
		while (s[i] && i < size)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	else if (point == 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

t_format	ft_flagpadding(t_format arg)
{
	if (arg.precision != 0 || arg.dash != 0)
		arg.zero = 0;
	if (arg.zero == 0)
		arg.conver = ' ';
	if (arg.zero == 1)
		arg.conver = '0';
	return (arg);
}

size_t	ft_printchar(int c, t_format arg)
{
	size_t	i;

	i = 0;
	arg = ft_flagpadding(arg);
	if (arg.dash != 0)
	{
		i += ft_putchar(c);
		while (i < arg.width && arg.width != 0)
			i += ft_putchar(arg.conver);
	}
	else if (arg.dash == 0)
	{
		while ((int)i < (int)(arg.width - 1) && arg.width != 0)
			i += ft_putchar(arg.conver);
		i += ft_putchar(c);
	}
	return (i);
}

size_t	ft_printstr(char *str, t_format arg)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	if (arg.precision == 0 && arg.point == 0)
		arg.precision = ft_strlen(str);
	arg = ft_flagpadding(arg);
	if (arg.dash != 0)
	{
		i += ft_putstr(str, arg.precision, arg.point);
		while (i < arg.width && arg.width != 0)
			i += ft_putchar(arg.conver);
	}
	else if (arg.dash == 0)
	{
		while ((int)i < (int)(arg.width - arg.precision) && arg.width != 0)
			i += ft_putchar(arg.conver);
		i += ft_putstr(str, arg.precision, arg.point);
	}
	return (i);
}
