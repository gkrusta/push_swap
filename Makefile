# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 12:25:10 by gkrusta           #+#    #+#              #
#    Updated: 2023/07/09 14:00:53 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

PUSHSWAP = ar rcs

SRCS =  main.c  rotate_instructions.c  rev_rotate_instructions.c \
		swap_instructions.c  push_instructions.c  index.c \
		valid_nb.c  sort3.c  sort4.c  sort5.c algorithm.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f	

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft1/ all
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft1/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft1/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft1/ fclean

re: fclean all

.PHONY: all clean fclean re