# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 12:53:44 by hzimmerm          #+#    #+#              #
#    Updated: 2024/06/10 14:55:17 by hzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CFLAGS = -g -Wall -Wextra -Werror -Isrcs/libft
SRCS = srcs/main.c srcs/making_stack.c srcs/sorting.c srcs/sorting_reverse.c srcs/costing.c srcs/moves.c srcs/targets.c \
	srcs/operations_one.c srcs/operations_two.c srcs/operations_three.c srcs/check_stack.c
BONUS_SRCS = bonus/main_bonus.c bonus/operations_one_bonus.c bonus/operations_two_bonus.c bonus/operations_three_bonus.c \
	bonus/check_stack_bonus.c bonus/costing_bonus.c bonus/making_stack_bonus.c bonus/sorting_bonus.c bonus/targets_bonus.c \
	bonus/sorting_reverse_bonus.c bonus/moves_bonus.c bonus/get_next_line_push_bonus.c bonus/make_operations_bonus.c
LDFLAGS = -fsanitize=address
LIBFT = srcs/libft/libft.a
LIB = srcs/libft
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -f "$(LIBFT)" ]; then \
		make -C $(LIB); \
	fi
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	chmod +x $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@if [ ! -f "$(LIBFT)" ]; then \
		make -C $(LIB); \
	fi
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	chmod +x $(BONUS_NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) srcs/*.o $(LIB)/*.o bonus/*.o

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean $(NAME) $(BONUS_NAME)

.PHONY: all clean fclean re
