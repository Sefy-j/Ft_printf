/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:53:53 by jlopez-f          #+#    #+#             */
/*   Updated: 2021/12/15 18:09:27 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_nblenp(unsigned long long n, int l, char *b, size_t i)
{
	unsigned long long	len;

	len = l;
	if (n > len - 1)
	{	
		i = ft_nblenp(n / len, len, b, i);
		i = ft_nblenp(n % len, len, b, i);
	}
	else
		i++;
	return (i);
}

size_t	ft_nblenx(unsigned int nb, int l, char *base, size_t i)
{
	unsigned int	len;

	len = l;
	if (nb > len - 1)
	{	
		i = ft_nblenx(nb / len, len, base, i);
		i = ft_nblenx(nb % len, len, base, i);
	}
	else
		i++;
	return (i);
}

size_t	ft_nblen(int nb, size_t i)
{
	if (nb == -2147483648)
	{
		i += 2;
		i = ft_nblen(147483648, i);
	}
	else if (nb < 0)
	{	
		i++;
		i = ft_nblen(-nb, i);
	}
	else if (nb > 9)
	{	
		i = ft_nblen(nb / 10, i);
		i = ft_nblen(nb % 10, i);
	}
	else
		i++;
	return (i);
}

size_t	ft_nblenu(unsigned int nb, size_t i)
{
	if (nb > 9)
	{	
		i = ft_nblenu(nb / 10, i);
		i = ft_nblenu(nb % 10, i);
	}
	else
		i++;
	return (i);
}
