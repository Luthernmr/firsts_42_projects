# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 15:03:20 by lnemor            #+#    #+#              #
#    Updated: 2022/02/07 15:53:09 by lnemor           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

LIBFT_DIR = libft

SRCS	=	main.c \
			philo.c
			
	
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= -Wall -Werror -Wextra -D_REENTRANT -g

RM		= 	rm -f

CLEAN	=	CLEAN

objs/%.o:%.c philo.h libft/libft.h libft/libft.a
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