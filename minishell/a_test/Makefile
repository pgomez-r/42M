# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 21:48:21 by pgomez-r          #+#    #+#              #
#    Updated: 2023/12/22 16:08:28 by pgruz11          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -g
LDFLAGS  = -lreadline 
NAME     = test

SRCS = $(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)

RM       = rm -f

all:	${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -c $?

$(NAME):	$(OBJS)
	@echo "\033[0;33m\n	 ##### Checking/compiling Libft_42 library #####\n\033[0m"
	@${MAKE} -C ../inc/libft
	@${CC} $(CFLAGS) $(OBJS) $(LDFLAGS) ../inc/libft/libft.a  -o $(NAME)
	@echo "\033[0;32m\n	 ##### Test program is ready! #####\n\033[0m"

clean:
		@${RM} ${OBJS}
		@${MAKE} -C ../inc/libft clean
		@echo "\033[0;32m\n	##### Object files have been removed #####\n\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@${MAKE} -C ../inc/libft fclean
		@echo "\033[0;32m\n	##### FCLEAN done! #####\n\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug
