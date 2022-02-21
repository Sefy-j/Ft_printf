/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:40:47 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/01/19 13:40:17 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

static unsigned long long int	ft_checknb(unsigned long long int nb, int s)
{
	unsigned long long int	nl;

	nl = 9223372036854775806;
	if (nb > nl && s > 0)
		return (-1);
	if (nb > nl + 1 && s < 0)
		return (0);
	return (nb);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						s;
	unsigned long long int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			s *= (-1);
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	r = ft_checknb(r, s);
	return ((int)r * s);
}

t_format	ft_miniparse(t_format arg, int j)
{
	arg.flagsize = j;
	arg.toprint = -1;
	return (arg);
}

t_format	ft_struct_init(t_format arg)
{
	arg.conver = '0';
	arg.width = 0;
	arg.precision = 0;
	arg.point = 0;
	arg.pad = 0;
	arg.zero = 0;
	arg.dash = 0;
	arg.space = 0;
	arg.plus = 0;
	arg.sign = 0;
	arg.toprint = 0;
	arg.flagsize = 0;
	arg.sign = 0;
	arg.size = 0;
	return (arg);
}
