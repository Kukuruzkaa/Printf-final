/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:31:42 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/12 13:39:13 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s(const char *fmt, t_flags *flags, va_list *args)
{
	flags->i++;
	fmt = va_arg(*args, char*);
	if (fmt == NULL)
		fmt = "(null)";
	flags->strlen = ft_strlen(fmt);
	if (flags->is_prec && flags->precision < flags->strlen)
		flags->strlen = flags->precision;
	if (flags->minus == 0)
	{
		if (flags->zero == 1)
		{
			fill_space(flags->width - flags->strlen, '0');
			ft_putstr(fmt, flags->strlen);
		}
		else
		{
			fill_space(flags->width - flags->strlen, ' ');
			ft_putstr(fmt, flags->strlen);
		}
	}
	else
	{
		ft_putstr(fmt, flags->strlen);
		fill_space(flags->width - flags->strlen, ' ');
	}
}
