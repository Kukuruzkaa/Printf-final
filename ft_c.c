/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:36:06 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:36:12 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c(t_flags *flags, va_list *args)
{
	unsigned char	c;

	flags->i++;
	c = va_arg(*args, int);
	if (flags->minus == 0)
	{
		if (flags->zero == 1)
		{
			fill_space(flags->width - 1, '0');
			ft_flush_char(c);
		}
		else
		{
			fill_space(flags->width - 1, ' ');
			ft_flush_char(c);
		}
	}
	else
	{
		ft_flush_char(c);
		fill_space(flags->width - 1, ' ');
	}
}
