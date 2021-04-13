/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:15:13 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/12 14:28:33 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbhexlength(long nb)
{
	long	l;

	l = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		l++;
	}
	return (l);
}

void	ft_putnbr_base(long n, char *base)
{
	long		nb;
	int			i;
	char		c;

	i = 0;
	nb = n;
	while (base[i])
		i++;
	if (n > 0)
	{
		c = base[nb % i];
		ft_putnbr_base(nb / i, base);
		ft_flush_char(c);
	}
}

int		nbplength(uintptr_t n)
{
	int		l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		l++;
	}
	return (l);
}

void	ft_putnbr_pbase(uintptr_t n, char *base)
{
	int			i;
	char		c;

	i = 0;
	while (base[i])
		i++;
	if (n > 0)
	{
		c = base[n % i];
		ft_putnbr_pbase(n / i, base);
		ft_flush_char(c);
	}
}
