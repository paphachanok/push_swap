# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoti <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 15:53:22 by ppoti             #+#    #+#              #
#    Updated: 2023/07/05 22:03:58 by ppoti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra
# FLAGS = -Wall -Werror -Wextra -g

SRCS =	main.c \
		utils_stack.c \
		input_checker.c \
		utils_join_av.c \
		utils_av.c \
		error_exit.c \
		stack.c \
		push_swap.c \
		utils_push_stack_p.c \
		set_cost_into_a.c \
		move_a_into_b.c \
		utils_push_stack_r.c \
		utils_push_stack_rr.c \
		utils_push_stack_s.c \
		tiny_sort_3.c \
		tiny_sort_5.c \
		set_cost_into_b.c \
		final_arrangement.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run:
	./push_swap $(ARG)

.PHONY: clean fclean all re
