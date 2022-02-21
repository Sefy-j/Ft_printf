/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:06:18 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/01/19 13:41:07 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

t_format	ft_flags(char c, t_format arg)
{
	if (c == '#')
		arg.pad = 1;
	if (c == '0')
		arg.zero = 1;
	if (c == '-')
		arg.dash = 1;
	if (c == ' ')
		arg.space = 1;
	if (c == '+')
		arg.plus = 1;
	return (arg);
}

t_format	ft_parseflags(const char *str, t_format arg, size_t i)
{
	size_t	j;

	j = i - 1;
	while (ft_strchr(FLAGS, str[i]))
	{
		arg = ft_flags(str[i], arg);
		i++;
	}
	arg.width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		arg.point = 1;
		arg.precision = ft_atoi(str + i + 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	arg.conver = str[i];
	if (ft_strchr(CONVERSIONS, str[i]))
		arg.flagsize = ++i;
	else
		ft_miniparse(arg, j);
	return (arg);
}

t_format	ft_print(t_format arg)
{
	if (arg.conver == 'c')
		arg.count += ft_printchar(va_arg(arg.data, int), arg);
	if (arg.conver == 's' )
		arg.count += ft_printstr(va_arg(arg.data, char *), arg);
	if (arg.conver == 'p')
		arg.count += ft_printmemory(va_arg(arg.data, unsigned long long), arg);
	if (arg.conver == 'd' || arg.conver == 'i')
		arg.count += ft_printnumber(va_arg(arg.data, int), arg);
	if (arg.conver == 'u')
		arg.count += ft_printunsigned(va_arg(arg.data, unsigned int), arg);
	if (arg.conver == 'x' || arg.conver == 'X')
		arg.count += ft_printhexa(va_arg(arg.data, unsigned int), arg);
	if (arg.conver == '%')
		arg.count += ft_putchar('%');
	arg = ft_struct_init(arg);
	return (arg);
}

int	ft_readarg(const char *str, t_format arg)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && arg.toprint == 0)
		{	
			arg = ft_parseflags(str, arg, ++i);
			i = arg.flagsize;
			if (arg.conver != '0' && arg.toprint == 0)
				arg = ft_print(arg);
		}
		else
		{
			arg.count += ft_putchar(str[i]);
			i++;
			arg.toprint = 0;
		}
	}
	return (arg.count);
}

int	ft_printf(const char *str, ...)
{
	t_format	arg;

	arg.count = 0;
	va_start(arg.data, str);
	arg = ft_struct_init(arg);
	arg.count = ft_readarg(str, arg);
	va_end(arg.data);
	return (arg.count);
}
