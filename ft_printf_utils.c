/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:40:30 by aalazhar          #+#    #+#             */
/*   Updated: 2021/12/01 19:59:21 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		j += ft_putchar(str[i]);
		i++;
	}
	return (j);
}

int	ft_putnbr(int nbr)
{
	int	j;

	j = 0;
	if (nbr == -2147483648)
	{
		j += ft_putchar('-');
		j += ft_putchar('2');
		j += ft_putnbr(147483648);
	}
	else if (nbr >= 0 && nbr <= 9)
		j += ft_putchar(nbr + '0');
	else if (nbr < 0)
	{
		j += ft_putchar('-');
		j += ft_putnbr(nbr * -1);
	}
	else
	{
		j += ft_putnbr(nbr / 10);
		j += ft_putnbr(nbr % 10);
	}
	return (j);
}

int	ft_put_phex(unsigned long nbr)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (nbr > 15)
	{
		j += ft_put_phex(nbr / 16);
		j += ft_put_phex(nbr % 16);
	}
	else
		j += ft_putchar(base[nbr]);
	return (j);
}
