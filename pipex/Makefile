# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 10:35:23 by lnemor            #+#    #+#              #
#    Updated: 2022/01/27 12:35:09 by lnemor           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

LIBFT_DIR = libft

SRCS	=	main.c \
			find_path.c \
			pipex.c \
			exit.c
	
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= -Wall -Werror -Wextra -ggdb3

RM		= 	rm -f

CLEAN	=	CLEAN

objs/%.o:%.c pipex.h libft/libft.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

all		: libft $(NAME)

libft	: 
		$(MAKE) -C libft

$(NAME)	:	$(addprefix objs/, $(OBJS)) 
			$(CC)  $(CFLAGS) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a

clean 	: 
		rm -rf 	objs
		make clean -C libft

fclean	: clean
		$(RM) $(NAME)
		make fclean -C libft

re :	fclean all
		make re -C libft

.PHONY: fclean clean all libft re