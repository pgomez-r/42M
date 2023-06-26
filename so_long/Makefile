# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 21:49:44 by pgomez-r          #+#    #+#              #
#    Updated: 2023/06/25 21:49:06 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
NAME     = so_long
BNAME    = so_long_bonus

SRC_PATH = src/
OBJ_PATH = obj/
B_PATH	 = bonus/

SRC      = main.c map_validate.c init.c load_images.c render_images.c \
			render_images_2.c animation.c animation_2.c key_control.c \
			key_control_2.c enemy_patrol.c enemy_patrol_2.c utils.c game_utils.c
SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

BSRC	 = main_bonus.c map_validate_bonus.c init_bonus.c load_images_bonus.c \
			render_images_bonus.c render_images_2_bonus.c animation_bonus.c \
			animation_2_bonus.c key_control_bonus.c key_control_2_bonus.c \
			enemy_patrol_bonus.c enemy_patrol_2_bonus.c utils_bonus.c game_utils_bonus.c
BSRCS	 = $(addprefix $(B_PATH), $(BSRC))
BOBJ	 = $(BSRC:.c=.o)
BOBJS	 = $(addprefix $(B_PATH), $(BOBJ))

RM       = rm -f

all:	${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
$(NAME):	$(OBJS)
	@echo "\033[0;33m\n	 ##### Checking/compiling Libft_42 library #####\n\033[0m"
	@${MAKE} -C ./incl/libft
	@echo "\033[0;33m\n	 ##### Checking/compiling MLX42 library #####\n\033[0m"
	@${MAKE} -C ./incl/MLX42
### - COMPILACIÓN PARA 42 - ###
	@${CC} $(CFLAGS) $(OBJS) ./incl/libft/libft.a ./incl/MLX42/libmlx42.a \
	-lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o $(NAME)
### - COMPILACIÓN PARA CASA - ###
#	@${CC} $(CFLAGS) $(OBJS) ./incl/libft/libft.a /home/pgruz/Escritorio/MLX42/linux_make/libmlx42.a \
	-Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "\033[0;32m\n	 ##### Game is ready, let's play! #####\n\033[0m"

bonus: ${BNAME}

$(B_PATH)%.o: $(B_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
${BNAME}:	${BOBJS}
	@echo "\033[0;33m\n	    ##### Checking/compiling Libft_42 library #####\n\033[0m"
	@${MAKE} -C ./incl/libft
	@echo "\033[0;33m\n	    ##### Checking/compiling MLX42 library #####\n\033[0m"
	@${MAKE} -C ./incl/MLX42
	@${CC} $(CFLAGS) $(BOBJS) ./incl/libft/libft.a ./incl/MLX42/libmlx42.a \
	-lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o $(BNAME)
	@echo "\033[0;32m\n	 ##### BONUS successfully created, let's play! #####\n\033[0m"

norm:
		@echo "\033[0;32m\n	 ##### Cheking 42_School_NORMINETTE #####\n\033[0m";
		@norminette src/
		@norminette bonus/
		@norminette incl/libft
		@norminette incl/so_long.h
		@norminette incl/so_long_bonus.h	

debug:
		@gcc -Wall -Wextra -Werror -g ./src/*.c ./incl/libft/libft.a \
		./incl/MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o debug 
		@echo "\033[0;32mDebug file successfully generated\033[0m"

clean:
		@${RM} ${OBJS} ${BOBJS}
		@${MAKE} -C ./incl/libft clean
		@echo "\033[0;32mObject files have been removed\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@${MAKE} -C ./incl/libft fclean
		@${MAKE} -C ./incl/MLX42 fclean
		@${RM} debug so_long_bonus
		@echo "\033[0;32mFCLEAN done!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug