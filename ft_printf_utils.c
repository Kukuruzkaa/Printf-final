/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:45:35 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/11 15:27:16 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flush_char(char c)
{
	g_return++;
	write(1, &c, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s, int maxlen)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < maxlen)
	{
		ft_putchar(s[i]);
		i++;
		g_return++;
	}
}

void	fill_space(int len, char c)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_flush_char(c);
		i++;
	}
}

int		ft_strchrint(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (*s == c)
		return (1);
	return (0);
}
