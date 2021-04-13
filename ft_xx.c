/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:18:58 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:19:45 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_prec_nominus(t_flags *flags, unsigned int n)
{
	if (n == 0 && flags->width == 0 && flags->precision == 0)
		return ;
	if (n == 0 && flags->width != 0 && flags->precision == 0)
	{
		fill_space(flags->width, ' ');
		return ;
	}
	fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	fill_space(flags->zero_filler, '0');
	ft_putnbr_base(n, "0123456789ABCDEF");
}

static void		ft_prec_minus(t_flags *flags, unsigned int n)
{
	if (n == 0 && flags->width != 0 && flags->precision == 0)
	{
		fill_space(flags->width, ' ');
		return ;
	}
	fill_space(flags->zero_filler, '0');
	ft_putnbr_base(n, "0123456789ABCDEF");
	fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
}

static void		ft_noprec_nominus(t_flags *flags, unsigned int n)
{
	if (flags->zero == 1)
	{
		if (flags->width)
			flags->zero_filler = flags->width - flags->strlen;
		fill_space(flags->zero_filler, '0');
		if (n == 0)
			ft_flush_char('0');
		ft_putnbr_base(n, "0123456789ABCDEF");
	}
	else
	{
		fill_space((flags->width - flags->strlen), ' ');
		if (n == 0)
			ft_flush_char('0');
		ft_putnbr_base(n, "0123456789ABCDEF");
	}
}

static void		ft_noprec_minus(t_flags *flags, unsigned int n)
{
	ft_putnbr_base(n, "0123456789ABCDEF");
	if (n == 0)
		ft_flush_char('0');
	fill_space((flags->width - flags->strlen), ' ');
}

void			ft_process_xx(t_flags *flags, va_list *args)
{
	unsigned int	x;

	flags->i++;
	x = va_arg(*args, unsigned int);
	flags->strlen = nbhexlength(x);
	if (x == 0 && flags->is_prec)
		flags->strlen = 0;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = 0;
	if (flags->is_prec && flags->minus == 0)
		ft_prec_nominus(flags, x);
	else if (flags->is_prec && flags->minus == 1)
		ft_prec_minus(flags, x);
	else if (flags->is_prec == 0 && flags->minus == 0)
		ft_noprec_nominus(flags, x);
	else if (flags->is_prec == 0 && flags->minus == 1)
		ft_noprec_minus(flags, x);
}
