# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:21:04 by pgomez-r          #+#    #+#              #
#    Updated: 2025/01/23 15:20:13 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -I./inc

SRC_PATH = src/
OBJ_PATH = obj/

SRC			= main Bureaucrat Form

SRCS		= $(addsuffix .cpp, $(addprefix $(SRC_PATH), $(SRC)))

OBJS		= $(SRCS:$(SRC_PATH)%.cpp=$(OBJ_PATH)/%.o)

RM			= rm -f

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
$(NAME):	$(OBJS)
	@${CC} $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m\n	 ##### ✅ Program $(NAME) is ready! ✅ #####\n\033[0m"

clean:
	@$(RM) $(OBJS) 
	@if [ -d $(OBJ_PATH) ]; then find $(OBJ_PATH) -type d -empty -delete; fi
	@echo "\033[0;32m\n	##### ✅ Object files and folders removed ✅ #####\n\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32m\n	##### ✅ Full clean done! ✅ #####\n\033[0m"

re: fclean all

.PHONY: all clean fclean re