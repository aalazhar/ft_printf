/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:55:56 by aalazhar          #+#    #+#             */
/*   Updated: 2021/12/01 20:01:15 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	is_true(char c)
{
	char	*base;
	int		i;

	i = 0;
	base = "cdisupxX";
	while (base[i])
	{
		if (c == base[i])
			return (c);
		i++;
	}
	return (-1);
}

static int	check_and_do(va_list args, char c)
{
	int	j;

	j = 0;
	if (c == 'p')
		j += ft_put_adress(va_arg(args, void *));
	if (c == 'x')
		j += ft_puthexnbr(va_arg(args, unsigned long));
	if (c == 'X')
		j += ft_put_hexnbr(va_arg(args, unsigned long));
	if (c == 'u')
		j += ft_putunbr(va_arg(args, unsigned int));
	if (c == 'd' || c == 'i')
		j += ft_putnbr(va_arg(args, int));
	if (c == 'c')
		j += ft_putchar(va_arg(args, int));
	if (c == 's')
		j += ft_putstr(va_arg(args, char *));
	return (j);
}

int	ft_printf(const char *frm, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	va_start(args, frm);
	while (frm[i])
	{
		if (frm[i] == '%')
		{
			i += 1;
			if (frm[i] == is_true(frm[i]))
			{
				j += check_and_do(args, is_true(frm[i]));
			}
			else if (frm[i] == '%')
				j += ft_putchar('%');
		}
		else
			j += ft_putchar(frm[i]);
		i++;
	}
	va_end(args);
	return (j);
}
