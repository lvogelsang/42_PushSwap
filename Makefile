# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 14:46:58 by lvogelsa          #+#    #+#              #
#    Updated: 2022/12/16 13:43:51 by lvogelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = buckets.c error.c index_sort.c index_sort_execution.c operations.c \
	push_swap.c push_swap_execution.c sort_short.c stack.c stack_attributes.c

BONUS_SRCS = checker.c \error.c \operations.c \stack.c \stack_attributes.c

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(NAME) $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(BONUS_NAME):
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS_NAME)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all
