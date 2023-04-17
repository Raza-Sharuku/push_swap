# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 10:38:14 by razasharuku       #+#    #+#              #
#    Updated: 2023/04/17 09:58:58 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = $(NAME)
NAME	=	push_swap 
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
INC		=	-I./libs/libft/ -I./libs/ft_printf/

SRCS	=	push_swap.c \
			ft_error.c \
			ft_atoi_4_swap.c \
			compress.c \
			push_swap_perform.c \
			rotate_perform.c \
			rev_rotate_perform.c \
			sort_1.c \
			sort_2.c \
			sort_3.c \
			sort_4.c \
			sort_5.c

OBJS = ${SRCS:%.c=%.o}

all:	$(NAME)

LIBFT		=	./libs/libft/libft.a
FT_PRINTF	=	./libs/ft_printf/libftprintf.a

$(NAME):	$(OBJS)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/ft_printf
	$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/ft_printf clean
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIBFT)
	$(RM) $(FT_PRINTF)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re