# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:02:29 by pgomez-r          #+#    #+#              #
#    Updated: 2023/03/26 22:50:39 by pgomez-r         ###   ########.fr        #
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

all:	${EXE}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo Generando archivos .o del programa...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Archivos objeto generados!
$(EXE):	$(OBJS)
	@echo Compilando libft42...
	@${MAKE} -C ./incl/libft42
	@${MAKE} -C ./incl/libft42 clean
	@${CC} $(CFLAGS) $(OBJS) ./incl/libft42/libft.a -o $(EXE)
	@echo Libft42 compilada!

clean:
		@${RM} ${OBJS}
		@echo Limpiados archivos objeto!

fclean:	clean
		@${RM} ${EXE}
		@${MAKE} -C ./incl/libft42 fclean
		@echo Fclean completado!

re:	fclean all

.PHONY: all clean fclean re