# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 12:25:10 by gkrusta           #+#    #+#              #
#    Updated: 2023/07/12 17:01:21 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSHSWAP = ar rcs

SRCS =  main.c  rotate_instructions.c  rev_rotate_instructions.c \
		swap_instructions.c  push_instructions.c  index.c \
		valid_nb.c  small_sort.c  algorithm.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f	

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32mCompiling Push Swap...\n"
	@make -C libft1/ all
	@make -C printf/ all
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft1/libft.a printf/libftprintf.a
	@ echo "\n\t\t\033[32mCompiled!\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C libft1/ clean
	@make -C printf/ clean
	@ echo "\n\t\t\033[32mEverything is clean!\n"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft1/ fclean
	@make -C printf/ fclean

re: fclean all

.PHONY: all clean fclean re