# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:45:11 by lnemor            #+#    #+#              #
#    Updated: 2021/12/02 15:19:49 by lnemor           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf_utils.c \
			ft_printf.c \

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= 	-Wall -Werror -Wextra

LIB 	= 	ar -rcs

RM		= 	rm -f

CLEAN	=	CLEAN

%.o:%.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

all		: $(NAME)

$(NAME)	:	$(OBJS)
		$(LIB) $(NAME) $(OBJS)

clean 	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re :	fclean all

.PHONY: fclean clean all re