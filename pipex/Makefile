# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:02:29 by pgomez-r          #+#    #+#              #
#    Updated: 2023/03/25 23:23:28 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
EXE      = pipex

SRC_PATH = src/
OBJ_PATH = obj/

SRC      = main.c
SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

RM       = rm -f

INC		= -I ./incl/

all:	${EXE}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
$(EXE):	$(OBJS)
	${CC} $(CFLAGS) $(OBJS) -o $(EXE)

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${EXE}

re:	fclean all

.PHONY: all clean fclean re