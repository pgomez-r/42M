# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:02:29 by pgomez-r          #+#    #+#              #
#    Updated: 2023/03/14 22:04:20 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE    = pipex

SRCS   = main.c 
			
OBJS   = $(SRCS:.c=.o)

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

RM     = rm -f

all:	${EXE}

$(EXE):	$(OBJS)
	${CC} $(CFLAGS) $(OBJS) -o $(EXE)

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${EXE}

re:	fclean all

.PHONY: all clean fclean re