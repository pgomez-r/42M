# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:51:47 by pgomez-r          #+#    #+#              #
#    Updated: 2022/12/23 14:45:53 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = split_atoi.c libft_utils.c main.c arg_check.c

OBJS	=	$(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME)
re: fclean all

.PHONY:	all clean fclean re