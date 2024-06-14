# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 09:29:12 by pgomez-r          #+#    #+#              #
#    Updated: 2024/06/14 01:26:42 by pgruz11          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Iinc

SRC_PATH = src/
OBJ_PATH = obj/


SRC 	= $(wildcard $(SRC_PATH)*.c) # List all .c files in SRC_PATH
OBJ		= $(SRC:$(SRC_PATH)%.c=%.o) # Transform .c to .o without path
OBJS	= $(addprefix $(OBJ_PATH),$(OBJ)) # 

# SRC 	= $(wildcard $(SRC_PATH)*.c)
# SRCS 	= $(addprefix $(SRC_PATH), $(SRC))
# OBJ		= $(SRC:.c=.o)
# OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

RM		= rm -f

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32mLibft42 compilada!\033[0m"

clean:
	@${RM} ${OBJS}
	@rmdir -p $(OBJ_PATH) 2>/dev/null || true

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus