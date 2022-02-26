/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:54:30 by aalazhar          #+#    #+#             */
/*   Updated: 2021/12/01 20:10:38 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putunbr(unsigned int nbr);
int	ft_puthexnbr(unsigned int nbr);
int	ft_put_hexnbr(unsigned int nbr);
int	ft_put_phex(unsigned long nbr);
int	ft_put_adress(void *nbr);
int	ft_printf(const char *frm, ...);

#endif
