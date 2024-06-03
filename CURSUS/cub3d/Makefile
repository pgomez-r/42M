# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 21:49:44 by pgomez-r          #+#    #+#              #
#    Updated: 2024/06/02 00:11:45 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = cub3d

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
# BNAME    = 

SRC_PATH = src/
OBJ_PATH = obj/
# B_PATH	 = bonus/

SRC      = main.c
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
	@${MAKE} -C ./inc/MLX42
### - COMPILACIÓN PARA 42 - ###
	@${CC} $(CFLAGS) $(OBJS) ./inc/libft/libft.a ./inc/MLX42/libmlx42.a \
	-lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o $(NAME)
### - COMPILACIÓN PARA CASA - ###
#	@${CC} $(CFLAGS) $(OBJS) ./inc/libft/libft.a /home/pgruz/Escritorio/MLX42/linux_make/libmlx42.a \
	-Iincude -ldl -lglfw -pthread -lm -o $(NAME)
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
		@norminette inc/so_long.h
		@norminette inc/so_long_bonus.h	

debug:
		@gcc -Wall -Wextra -Werror -g ./src/*.c ./inc/libft/libft.a \
		./inc/MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ -o debug 
		@echo "\033[0;32mDebug file successfully generated\033[0m"

clean:
		@${RM} ${OBJS} ${BOBJS}
		@${MAKE} -C ./inc/libft clean
		@echo "\033[0;32mObject files have been removed\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@${MAKE} -C ./inc/libft fclean
		@${MAKE} -C ./inc/MLX42 fclean
		@${RM} debug so_long_bonus
		@echo "\033[0;32mFCLEAN done!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug