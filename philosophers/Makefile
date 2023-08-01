# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 21:59:35 by pgruz             #+#    #+#              #
#    Updated: 2023/08/01 19:42:27 by pgruz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -pthread -fsanitize=thread
NAME     = philo
# BNAME    = philo_bonus

SRC_PATH = src/
OBJ_PATH = obj/
# B_PATH	 = bonus/

SRC      = main.c
SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

# BSRC	 = 
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
	@${MAKE} -C ./incl/libft
	@${CC} $(CFLAGS) $(OBJS) ./incl/libft/libft.a -o $(NAME)
	@echo "\033[0;32m\n	 ##### Philo is ready! #####\n\033[0m"

# bonus: ${BNAME}

# $(B_PATH)%.o: $(B_PATH)%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# ${BNAME}:	${BOBJS}
# 	@echo "\033[0;33m\n	    ##### Checking/compiling Libft_42 library #####\n\033[0m"
# 	@${MAKE} -C ./incl/libft
# 	@${CC} $(CFLAGS) $(BOBJS) ./incl/libft/libft.a -o $(BNAME)
# 	@echo "\033[0;32m\n	 ##### BONUS successfully created! #####\n\033[0m"

norm:
		@echo "\033[0;32m\n	 ##### Cheking 42_School_NORMINETTE #####\n\033[0m";
		@norminette src/
		@norminette bonus/
		@norminette incl/libft
		@norminette incl/philo.h
		@norminette incl/philo_bonus.h	

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
		@${RM} ${BNAME} debug
		@echo "\033[0;32mFCLEAN done!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug