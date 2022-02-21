/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:51:03 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/21 18:22:29 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_format
{
	va_list	data;
	char	conver;
	size_t	width;
	size_t	precision;
	size_t	point;
	size_t	pad;
	size_t	zero;
	size_t	dash;
	size_t	space;
	size_t	plus;
	size_t	sign;
	size_t	toprint;
	size_t	flagsize;
	size_t	count;
	size_t	size;
}	t_format;

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "#0- +"
# define HEXAUP "0123456789ABCDEF"
# define HEXALW "0123456789abcdef"
# define DIRUP "0X"
# define DIRLW "0x"

char		*ft_strchr(const char *str, int c);
int			ft_printf(const char *str, ...);
int			ft_atoi(const char *str);
size_t		ft_nblen(int nb, size_t i);
size_t		ft_nblenu(unsigned int nb, size_t i);
size_t		ft_nblenp(unsigned long long n, int l, char *b, size_t i);
size_t		ft_nblenx(unsigned int nb, int l, char *base, size_t i);
size_t		ft_strlen(const char *str);
size_t		ft_putstr(char *s, ssize_t size, size_t point);
size_t		ft_putchar(char c);
size_t		ft_printchar(int c, t_format arg);
size_t		ft_printstr(char *str, t_format arg);
size_t		ft_printmemory(unsigned long long int nb, t_format arg);
size_t		ft_printhexa(unsigned int nb, t_format arg);
size_t		ft_printnumber(int nb, t_format arg);
size_t		ft_printunsigned(unsigned int nb, t_format arg);
t_format	ft_struct_init(t_format arg);
t_format	ft_checknbrflag(t_format arg, int nb, char *exsign);
t_format	ft_checkunbrflag(t_format arg, unsigned int nb);
t_format	ft_checkflagx(t_format arg, unsigned int nb);
t_format	ft_checkflagp(t_format arg);
t_format	ft_miniparse(t_format arg, int j);
#endif
