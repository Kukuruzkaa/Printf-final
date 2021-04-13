/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:37:56 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/12 13:49:26 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_perc(t_flags *flags)
{
	flags->i++;
	if (flags->minus == 0)
	{
		if (flags->zero == 1)
		{
			fill_space(flags->width - 1, '0');
			ft_flush_char('%');
		}
		else
		{
			fill_space(flags->width - 1, ' ');
			ft_flush_char('%');
		}
	}
	else
	{
		ft_flush_char('%');
		fill_space(flags->width - 1, ' ');
	}
}
