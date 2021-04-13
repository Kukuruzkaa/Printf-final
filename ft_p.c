/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:37:39 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:37:44 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_prec_nominus(t_flags *flags, uintptr_t n)
{
	if (n == 0 && flags->width == 0 && flags->precision == 0)
	{
		ft_putstr("0x", 2);
		return ;
	}
	if (n == 0 && flags->width != 0 && flags->precision == 0)
	{
		fill_space(flags->width - 2, ' ');
		ft_putstr("0x", 2);
		return ;
	}
	fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	ft_putstr("0x", 2);
	fill_space(flags->zero_filler, '0');
	ft_putnbr_pbase(n, "0123456789abcdef");
}

static void		ft_prec_minus(t_flags *flags, uintptr_t n)
{
	if (n == 0 && flags->width != 0 && flags->precision == 0)
	{
		fill_space(flags->width, ' ');
		return ;
	}
	fill_space(flags->zero_filler, '0');
	ft_putstr("0x", 2);
	ft_putnbr_pbase(n, "0123456789abcdef");
	fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
}

static void		ft_noprec_nominus(t_flags *flags, uintptr_t n)
{
	if (flags->zero == 1)
	{
		if (flags->width)
			flags->zero_filler = flags->width - flags->strlen;
		fill_space(flags->zero_filler, '0');
		if (n == 0)
			ft_flush_char('0');
		ft_putstr("0x", 2);
		ft_putnbr_pbase(n, "0123456789abcdef");
	}
	else
	{
		fill_space((flags->width - flags->strlen), ' ');
		ft_putstr("0x", 2);
		if (n == 0)
			ft_flush_char('0');
		ft_putnbr_pbase(n, "0123456789abcdef");
	}
}

static void		ft_noprec_minus(t_flags *flags, uintptr_t n)
{
	ft_putstr("0x", 2);
	ft_putnbr_pbase(n, "0123456789abcdef");
	if (n == 0)
		ft_flush_char('0');
	fill_space((flags->width - flags->strlen), ' ');
}

void			ft_process_p(t_flags *flags, va_list *args)
{
	void		*p;
	uintptr_t	n;

	flags->i++;
	p = va_arg(*args, void*);
	n = (uintptr_t)p;
	flags->strlen = nbplength(n) + 2;
	if (p == 0 && flags->is_prec)
		flags->strlen = 0;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = 0;
	if (flags->is_prec && flags->minus == 0)
		ft_prec_nominus(flags, n);
	else if (flags->is_prec && flags->minus == 1)
		ft_prec_minus(flags, n);
	else if (flags->is_prec == 0 && flags->minus == 0)
		ft_noprec_nominus(flags, n);
	else if (flags->is_prec == 0 && flags->minus == 1)
		ft_noprec_minus(flags, n);
}
