# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 15:03:20 by lnemor            #+#    #+#              #
#    Updated: 2022/02/15 17:03:31 by lnemor           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	philo


SRCS	=	main.c \
			philo.c \
			print_msg.c \
			init_philo_mutex.c \
			utils.c
			
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= -Wall -Werror -Wextra #-g -fsanitize=thread

RM		= 	rm -f

CLEAN	=	CLEAN

objs/%.o:%.c philo.h Makefile
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@ 

all		: $(NAME)

$(NAME)	:	$(addprefix objs/, $(OBJS)) 
			$(CC)  $(CFLAGS) -o $(NAME) $(addprefix objs/, $(OBJS)) 

clean 	: 
		rm -rf 	objs

fclean	: clean
		$(RM) $(NAME)

re :	fclean all

.PHONY: fclean clean all re