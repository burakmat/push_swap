# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmat <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 16:12:40 by bmat              #+#    #+#              #
#    Updated: 2022/08/14 21:10:30 by bmat             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SRCS = apply.c main_sort.c main.c ps_double_functions.c ps_functions.c \
	sort_utils_one.c sort_utils_two.c sort_utils_three.c sort_utils_four.c \
	sort_utils_five.c sort_utils_six.c utils_one.c utils_two.c utils_three.c \
	stack_utils.c
BONUS_SRCS = main_bonus.c stack_utils.c ps_checker_functions.c \
			 ps_checker_double_functions.c sort_utils_five.c utils_one.c \
			 utils_two.c utils_three.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS)

bonus: $(BONUS)

re: fclean all

.PHONY: all clean fclean re
