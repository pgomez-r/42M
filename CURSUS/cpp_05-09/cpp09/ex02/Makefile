# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:51:45 by pgomez-r          #+#    #+#              #
#    Updated: 2025/02/18 11:14:28 by pgruz11          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror -I./inc

SRC_PATH = src/
OBJ_PATH = obj/

SRC			= main PmergeMe

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

leaks:
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) $(ARGS)

.PHONY: all clean fclean re leaks