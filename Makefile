# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 12:25:10 by gkrusta           #+#    #+#              #
#    Updated: 2023/07/19 11:52:01 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

PUSHSWAP = ar rcs

SRCS =  main.c  locate.c  rotate_instructions.c  rev_rotate_instructions.c \
		swap_instructions.c  push_instructions.c  index.c \
		valid_nb.c  small_sort.c  algorithm.c print_stacks.c

SRCS_BONUS =  push_swap_bonus/checker.c  locate.c  rotate_instructions.c  rev_rotate_instructions.c \
		swap_instructions.c  push_instructions.c  index.c \
		valid_nb.c  small_sort.c  algorithm.c 

#PATH = push_swap_bonus/

#SRC_WITH_PATH = addprefix($(PATH), $(SRCS_BONUS))

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ echo "\033[32mCompiling Push Swap...\n"
	@ make -C libft1/ all
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) libft1/libft.a
	@ echo "\n\t\t\033[32mCompiled!\n"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@ echo "\033[32mCompiling Push Swap BONUS...\n"
	@ make -C libft1/ all
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) libft1/libft.a
	@ echo "\n\t\t\033[32mCompiled!\n"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJS) $(OBJS_BONUS)
	@ make -C libft1/ clean
	@ echo "\n\t\t\033[32mEverything is clean!\n"

fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@ make -C libft1/ fclean

re: fclean all bonus

.PHONY: all clean fclean re bonus