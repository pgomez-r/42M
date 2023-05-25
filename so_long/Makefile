# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 21:49:44 by pgomez-r          #+#    #+#              #
#    Updated: 2023/05/25 22:31:18 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
NAME     = so_long

SRC_PATH = src/
OBJ_PATH = obj/

SRC      = main.c init_struct.c init.c load_images.c render_images.c render_images_2.c
SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

RM       = rm -f

all:	${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[0;33mGenerando archivos objeto...\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mArchivos objeto generados!"
$(NAME):	$(OBJS)
	@echo "\033[0;33mComprobando/compilando libft42...\033[0m"
	@${MAKE} -C ./incl/libft
	@echo "\033[0;33mComprobando/compilando MLX42...\033[0m"
	@${MAKE} -C ./incl/MLX42
	@echo "\033[0;32mMLX42 compilada!\033[0m"
### - COMPILACIÓN PARA 42 - ###
	@${CC} $(CFLAGS) $(OBJS) ./incl/libft/libft.a ./incl/MLX42/libmlx42.a \
	-lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o $(NAME)
### - COMPILACIÓN PARA CASA - ###
#	@${CC} $(CFLAGS) $(OBJS) ./incl/libft/libft.a /home/pgruz/Escritorio/MLX42/linux_make/libmlx42.a \
	-Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "\033[0;32mEjecutable creado!\033[0m"

debug:
		@gcc -Wall -Wextra -Werror -g ./src/*.c ./incl/libft/libft.a \
		./incl/MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o debug 
		@echo "\033[0;32mArchivo debug generado"

clean:
		@${RM} ${OBJS}
		@${MAKE} -C ./incl/libft clean
		@echo "\033[0;32mLimpiados archivos objeto!\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@${MAKE} -C ./incl/libft fclean
		@${RM} debug
		@echo "\033[0;32mFclean completado!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug