# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 13:57:56 by ddiakova          #+#    #+#              #
#    Updated: 2021/04/11 15:50:38 by ddiakova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a


SRCS 			= checker.c \
				ft_printf_utils.c \
				ft_convert_dec_bases.c \
				ft_convert_hex_bases.c \
				ft_x.c \
				ft_xx.c \
				ft_c.c \
				ft_s.c \
				ft_di.c \
				ft_u.c \
				ft_printf.c \
				ft_perc.c \
				ft_p.c \

OBJS			= $(SRCS:%.c=%.o)

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra -g -c

INCLUDE 		= ft_printf.h

all:			$(NAME)

.c.o:
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS) 
									make -C ./libft/
									cp ./libft/libft.a ./$(NAME)
									ar rcs $(NAME) $(OBJS)

$(OBJS):		$(SRCS)
				gcc $(CFLAGS) $(SRCS) -I $(INCLUDE)

clean:
				$(RM) $(OBJS)
					make clean -C ./libft

fclean:			clean
				$(RM) $(NAME)
					make fclean -C ./libft

re: 			fclean all

.PHONY: 		all clean fclean re bonus
