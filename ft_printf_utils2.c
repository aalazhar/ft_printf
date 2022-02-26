/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:43:50 by aalazhar          #+#    #+#             */
/*   Updated: 2021/12/01 20:05:58 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	j;

	j = 0;
	if (nbr >= 0 && nbr <= 9)
		j += ft_putchar(nbr + '0');
	else
	{
		j += ft_putunbr(nbr / 10);
		j += ft_putunbr(nbr % 10);
	}
	return (j);
}

int	ft_put_hexnbr(unsigned int nbr)
{
	char	*base;
	int		j;

	base = "0123456789ABCDEF";
	j = 0;
	if (nbr > 15)
	{
		j += ft_put_hexnbr(nbr / 16);
		j += ft_put_hexnbr(nbr % 16);
	}
	else
		j += ft_putchar(base[nbr]);
	return (j);
}

int	ft_puthexnbr(unsigned int nbr)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (nbr > 15)
	{
		j += ft_puthexnbr(nbr / 16);
		j += ft_puthexnbr(nbr % 16);
	}
	else
		j += ft_putchar(base[nbr]);
	return (j);
}

int	ft_put_adress(void *nbr)
{
	int	j;

	j = 0;
	j += write(1, "0x", 2);
	j += ft_put_phex((unsigned long)nbr);
	return (j);
}
