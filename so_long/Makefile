# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 10:35:23 by lnemor            #+#    #+#              #
#    Updated: 2022/01/19 13:58:55 by lnemor           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT_DIR = libft

SRCS	=	main.c	\
			init_mlx.c \
			hooks.c	\
			parse_map.c \
			get_next_line.c \
			window_size.c \
			check_error.c \
			fill_map.c \
			return_error.c
	
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= 	-Wall -Werror -Wextra

RM		= 	rm -f

CLEAN	=	CLEAN

objs/%.o:%.c so_long.h libft/libft.h mlx/mlx.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

all		: libft $(NAME)

libft	: 
		$(MAKE) -C libft
		$(MAKE) -C mlx

$(NAME)	:	$(addprefix objs/, $(OBJS)) 
			$(CC)  $(CFLAGS) -o $(NAME) $(addprefix objs/, $(OBJS)) -Lmlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a

clean 	: 
		rm -rf 	objs
		make clean -C libft
		make clean -C mlx

fclean	: clean
		$(RM) $(NAME)
		make fclean -C libft
		
re :	fclean all
		make re -C libft
		make re -C mlx

.PHONY: fclean clean all libft re mlx