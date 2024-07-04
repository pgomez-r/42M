# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 21:49:44 by pgomez-r          #+#    #+#              #
#    Updated: 2024/06/30 21:43:51 by pgruz11          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

# macOS (12.0) - With GLFW installed with homebrew
ifeq ($(UNAME), Darwin)
CMAKE_CMD = cmake -B ./inc/MLX42/build ./inc/MLX42 -DCMAKE_OSX_DEPLOYMENT_TARGET=12.0
GLFW_LINK = -lglfw -Iinclude -L/Users/${USER}/.brew/opt/glfw/lib
# Ubuntu (22.04) - With GLFW core installed (not homebrew)
else ifeq ($(UNAME), Linux)
CMAKE_CMD = cmake -B ./inc/MLX42/build ./inc/MLX42
GLFW_LINK = -Iinclude -ldl -lglfw -pthread -lm
endif

NAME     = cub3d

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -I./inc
# BNAME    = 

SRC_PATH = src/
OBJ_PATH = obj/
# B_PATH	 = bonus/

SRC      = main.c init.c key_control.c load_images.c raycast.c

SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

# BSRC	 = main_bonus.c
# BSRCS	 = $(addprefix $(B_PATH), $(BSRC))
# BOBJ	 = $(BSRC:.c=.o)
# BOBJS	 = $(addprefix $(B_PATH), $(BOBJ))

RM       = rm -f

all:	${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
$(NAME):	$(OBJS)
	@echo "\033[0;33m\n	 ##### Checking/compiling Libft_42 library #####\n\033[0m"
	@${MAKE} -C ./inc/libft
	@echo "\033[0;33m\n	 ##### Checking/compiling MLX42 library #####\n\033[0m"
	@${CMAKE_CMD}
	@make -C ./inc/MLX42/build -j4
	@echo "\033[0;33m\n	 ##### Checking/compiling CVB3D #####\n\033[0m"
	@${CC} $(CFLAGS) $(OBJS) ./inc/libft/libft.a ./inc/MLX42/build/libmlx42.a \
	${GLFW_LINK} -o $(NAME)
	@echo "\033[0;32m\n	 ##### Game is ready, let's play! #####\n\033[0m"

# bonus: ${BNAME}

# $(B_PATH)%.o: $(B_PATH)%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# ${BNAME}:	${BOBJS}
# 	@echo "\033[0;33m\n	    ##### Checking/compiling Libft_42 library #####\n\033[0m"
# 	@${MAKE} -C ./inc/libft
# 	@echo "\033[0;33m\n	    ##### Checking/compiling MLX42 library #####\n\033[0m"
# 	@${MAKE} -C ./inc/MLX42
# 	@${CC} $(CFLAGS) $(BOBJS) ./inc/libft/libft.a ./inc/MLX42/libmlx42.a \
# 	-lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o $(BNAME)
# 	@echo "\033[0;32m\n	 ##### BONUS successfully created, let's play! #####\n\033[0m"

norm:
		@echo "\033[0;32m\n	 ##### Cheking 42_School_NORMINETTE #####\n\033[0m";
		@norminette src/
		@norminette bonus/
		@norminette inc/libft
		@norminette inc/cub3d.h
		@norminette inc/cub3d_bonus.h	

debug:
		@gcc -Wall -Wextra -Werror -g ./src/*.c ./inc/libft/libft.a \
		./inc/MLX42/build/libmlx42.a ${GLFW_LINK} -o debug 
		@echo "\033[0;32mDebug file successfully generated\033[0m"

clean:
		@${RM} ${OBJS} ${BOBJS}
		@rmdir -p $(OBJ_PATH) 2>/dev/null || true
		@${MAKE} -C ./inc/libft clean
		@echo "\033[0;32mObject files have been removed\033[0m"

fclean:	clean
		@${RM} ${NAME} ${BNAME}
		@${MAKE} -C ./inc/libft fclean
		@if [ -d "./inc/MLX42/build" ]; then ${MAKE} -C ./inc/MLX42/build clean; fi
		@${RM} debug
		@echo "\033[0;32mFCLEAN done!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug