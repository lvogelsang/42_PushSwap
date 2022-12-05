# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 14:46:58 by lvogelsa          #+#    #+#              #
#    Updated: 2022/12/05 16:14:20 by lvogelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LINKS = -L $(LIBFT_PATH) -lft

SRCS = buckets.c error.c operations.c push_swap.c push_swap_execution.c \
	sort_short.c stack.c stack_attributes.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker.c \error.c \operations.c \stack.c \stack_attributes.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(LIBFT):
	make -C $(LIBFT_PATH)

all: $(LIBFT) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	cp $(LIBFT) $(NAME)
	-o $(NAME) $(OBJS) $(LINKS)

bonus: libft $(BONUS_OBJS)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) $(CFLAGS) -L $(LIBFT_PATH) -lft

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

fclean_bonus: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(BONUS_NAME)

re: fclean all

re_bonus: fclean_bonus alll
