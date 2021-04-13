/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:58:11 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:28:35 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nblength(long nb)
{
	int		l;

	l = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

void	ft_putnbr(long int n)
{
	long int	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_flush_char(nb + 48);
}

void	ft_di_negatif(t_flags *flags, long int *n)
{
	*n *= -1;
	flags->neg_number = 1;
}
