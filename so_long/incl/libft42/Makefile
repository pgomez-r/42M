# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 09:29:12 by pgomez-r          #+#    #+#              #
#    Updated: 2023/05/04 21:29:33 by pgomez-r         ###   ########.fr        #
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
	@echo "\033[0;32mLibft42 compilada!\033[0m"
	
all: $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY:	all clean fclean re bonus