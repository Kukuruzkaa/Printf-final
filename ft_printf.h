/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:52:05 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/13 12:21:29 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_flags
{
	int		width;
	int		precision;
	int		is_prec;
	int		zero_filler;
	int		neg_number;
	int		minus;
	int		zero;
	int		strlen;
	int		i;
	char	type;
}				t_flags;

int				g_return;

void			ft_putchar(char c);
int				ft_printf(const char *fmt, ...);
int				ft_strchrint(const char *s, int c);
void			check_fmt(const char *s, t_flags *flags, va_list *ap);
void			ft_process_c(t_flags *flags, va_list *args);
void			fill_space(int len, char c);
void			ft_putstr(const char *s, int maxlen);
void			ft_process_s(const char *fmt, t_flags *flags, va_list *args);
void			ft_process_di(t_flags *flags, va_list *args);
void			ft_process_u(t_flags *flags, va_list *args);
void			ft_process_x(t_flags *flags, va_list *args);
void			ft_flush_char(char c);
void			ft_process_perc(t_flags *flags);
void			ft_process_p(t_flags *flags, va_list *args);
void			ft_process_xx(t_flags *flags, va_list *args);
int				nblength(long nb);
int				nbhexlength(long nb);
int				nbplength(uintptr_t n);
void			ft_putnbr(long int n);
void			ft_putnbr_base(long n, char *base);
void			ft_putnbr_pbase(uintptr_t n, char *base);
void			ft_di_negatif(t_flags *flags, long int *n);

#endif
