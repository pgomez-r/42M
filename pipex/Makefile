# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:02:29 by pgomez-r          #+#    #+#              #
#    Updated: 2023/03/27 23:23:12 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Por revisar si me está haciendo relink -> siempre imprime la compilación de
#libft pero creo que no lo está ejecutando, igualmente me gustaría sacarlo a
#una receta independiente que solo se ejecute si no existe el arhivo libft.a

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
	@echo "\033[0;33mGenerando archivos objeto...\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mArchivos objeto generados!"
$(EXE):	$(OBJS)
	@echo "\033[0;33mCompilando libft42...\033[0m"
	@${MAKE} -C ./incl/libft42
	@echo "\033[0;32mLibft42 compilada!\033[0m"
	@${CC} $(CFLAGS) $(OBJS) ./incl/libft42/libft.a -o $(EXE)
	@echo "\033[0;32mEjecutable creado!\033[0m"

debug:
		@gcc -Wall -Wextra -Werror -g ./src/*.c ./incl/libft42/libft.a -o debug
		@echo "\033[0;32mArchivo debug generado"

clean:
		@${RM} ${OBJS}
		@${MAKE} -C ./incl/libft42 clean
		@echo "\033[0;32mLimpiados archivos objeto!\033[0m"

fclean:	clean
		@${RM} ${EXE}
		@${MAKE} -C ./incl/libft42 fclean
		@${RM} debug
		@echo "\033[0;32mFclean completado!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug