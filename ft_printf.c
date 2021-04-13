/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:57:08 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:27:38 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_case(t_flags *flags, va_list *args, const char *fmt)
{
	if (fmt[flags->i] == 'c')
		ft_process_c(flags, args);
	else if (fmt[flags->i] == 's')
		ft_process_s(fmt, flags, args);
	else if (fmt[flags->i] == 'p')
		ft_process_p(flags, args);
	else if (fmt[flags->i] == 'd' || fmt[flags->i] == 'i')
		ft_process_di(flags, args);
	else if (fmt[flags->i] == 'u')
		ft_process_u(flags, args);
	else if (fmt[flags->i] == 'x')
		ft_process_x(flags, args);
	else if (fmt[flags->i] == 'X')
		ft_process_xx(flags, args);
	else if (fmt[flags->i] == '%')
		ft_process_perc(flags);
}

int				ft_printf(const char *fmt, ...)
{
	t_flags flags;
	va_list args;

	va_start(args, fmt);
	flags.i = 0;
	g_return = 0;
	while (fmt[flags.i] != '\0')
	{
		if (fmt[flags.i] != '%')
			ft_flush_char(fmt[flags.i]);
		if (fmt[flags.i] == '%')
		{
			while (fmt[flags.i] != '\0' && fmt[flags.i] == '%')
			{
				flags.i++;
				check_fmt(fmt, &flags, &args);
				check_case(&flags, &args, fmt);
			}
		}
		else
			flags.i++;
	}
	va_end(args);
	return (g_return);
}
