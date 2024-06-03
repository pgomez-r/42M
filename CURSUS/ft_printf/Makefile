# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:51:47 by pgomez-r          #+#    #+#              #
#    Updated: 2022/11/22 08:19:54 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_print_formats.c

OBJS	=	$(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

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