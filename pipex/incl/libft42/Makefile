# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 09:29:12 by pgomez-r          #+#    #+#              #
#    Updated: 2023/03/26 22:17:00 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)
			
CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME = libft.a

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	
all: $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY:	all clean fclean re bonus