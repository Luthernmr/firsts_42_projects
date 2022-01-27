# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 10:35:23 by lnemor            #+#    #+#              #
#    Updated: 2022/01/10 17:21:33 by lnemor           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT_DIR = libft

SRCS	=	check_double.c			\
			check_num_b.c			\
			do_pa.c					\
			do_pb.c					\
			do_ra.c					\
			do_rb.c					\
			do_rr.c					\
			do_rra.c				\
			do_rrb.c				\
			do_rrr.c				\
			do_sa.c					\
			do_sb.c					\
			do_ss.c					\
			error.c					\
			find_smallest.c			\
			is_in_median.c			\
			parse_argument.c		\
			main.c					\
			ra_to_pb.c				\
			rb_or_rrb.c				\
			sort_five_hundred_nb.c	\
			sort_five_nb.c			\
			sort_hundred_nb.c		\
			sort_three_nb.c			\
			sorting.c				\
			up_pile.c			
	
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= 	-Wall -Werror -Wextra

RM		= 	rm -f

CLEAN	=	CLEAN

objs/%.o:%.c push_swap.h libft/libft.h
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