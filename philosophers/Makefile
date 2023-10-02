# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 21:59:35 by pgruz             #+#    #+#              #
#    Updated: 2023/10/02 21:11:26 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -pthread
NAME     = philo
# BNAME    = philo_bonus

SRC_PATH = src/
OBJ_PATH = obj/
# B_PATH	 = bonus/

SRC      = main.c utils.c utils_2.c parse.c
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
	@${CC} $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m\n	 ##### Philo is ready! #####\n\033[0m"

# bonus: ${BNAME}

# $(B_PATH)%.o: $(B_PATH)%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# ${BNAME}:	${BOBJS}
# 	@${CC} $(CFLAGS) $(BOBJS) -o $(BNAME)
# 	@echo "\033[0;32m\n	 ##### BONUS successfully created! #####\n\033[0m"

norm:
		@echo "\033[0;32m\n	 ##### Cheking 42_School_NORMINETTE #####\n\033[0m";
		@norminette src/
		@norminette bonus/
		@norminette incl/philo.h
		@norminette incl/philo_bonus.h	

debug:
		@gcc -Wall -Wextra -Werror -pthread -fsanitize=thread -g ./src/*.c -o debug 
		@echo "\033[0;32mDebug file successfully generated\033[0m"

clean:
		@${RM} ${OBJS} ${BOBJS}
		@echo "\033[0;32mObject files have been removed\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@${RM} ${BNAME} debug
		@echo "\033[0;32mFCLEAN done!\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug