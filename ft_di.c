/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:38:21 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:38:27 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_prec_nominus(t_flags *flags, long n)
{
	if (n == 0 && flags->width == 0 && flags->precision == 0)
	{
		return ;
	}
	else if (n == 0 && flags->width != 0 && flags->precision == 0)
	{
		fill_space(flags->width, ' ');
		return ;
	}
	fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	if (flags->neg_number)
		ft_flush_char('-');
	fill_space(flags->zero_filler, '0');
	ft_putnbr(n);
}

static void		ft_prec_minus(t_flags *flags, long n)
{
	if (n == 0 && flags->width != 0 && flags->precision == 0)
	{
		fill_space(flags->width, ' ');
		return ;
	}
	else if (n == 0 && flags->width == 0 && flags->precision == 0)
	{
		fill_space(flags->width, ' ');
		return ;
	}
	if (flags->neg_number)
		ft_flush_char('-');
	fill_space(flags->zero_filler, '0');
	ft_putnbr(n);
	fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
}

static void		ft_noprec_nominus(t_flags *flags, long n)
{
	if (flags->zero == 1)
	{
		if (flags->width)
			flags->zero_filler = flags->width - flags->strlen;
		if (flags->neg_number)
			ft_flush_char('-');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(n);
	}
	else
	{
		fill_space((flags->width - flags->strlen), ' ');
		if (flags->neg_number)
			ft_flush_char('-');
		ft_putnbr(n);
	}
}

static void		ft_noprec_minus(t_flags *flags, long n)
{
	if (flags->neg_number)
		ft_flush_char('-');
	ft_putnbr(n);
	fill_space((flags->width - flags->strlen), ' ');
}

void			ft_process_di(t_flags *flags, va_list *args)
{
	long	di;

	flags->i++;
	di = va_arg(*args, int);
	if (di < 0)
		ft_di_negatif(flags, &di);
	flags->strlen = nblength(di);
	if (di == 0 && flags->is_prec)
		flags->strlen = 1;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = 0;
	if (flags->neg_number)
		flags->strlen++;
	if (flags->is_prec && flags->minus == 0)
		ft_prec_nominus(flags, di);
	else if (flags->is_prec && flags->minus == 1)
		ft_prec_minus(flags, di);
	else if (flags->minus == 0 && flags->is_prec == 0)
		ft_noprec_nominus(flags, di);
	else if (flags->minus == 1 && flags->is_prec == 0)
		ft_noprec_minus(flags, di);
}
