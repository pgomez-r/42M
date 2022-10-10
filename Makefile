# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 09:29:12 by pgomez-r          #+#    #+#              #
#    Updated: 2022/10/05 12:57:25 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c 
# *PREGUNTA: ¿Se podría cambiar toda la lista de archivos .c por *.c? * #
OBJS	=	$(SRCS:.c=.o) *

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I.

$(NAME):
	gcc -c $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY:	all clean fclean re