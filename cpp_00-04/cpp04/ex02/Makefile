# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:21:04 by pgomez-r          #+#    #+#              #
#    Updated: 2024/05/30 08:54:49 by pgruz11          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.cpp Cat.cpp Dog.cpp AAnimal.cpp Brain.cpp WrongAnimal.cpp \
		WrongCat.cpp

SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.cpp=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

RM = rm -f

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
$(NAME):	$(OBJS)
	@${CC} $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m\n	 ##### Program is ready! #####\n\033[0m"

clean:
	@$(RM) $(OBJS) 
	@rmdir -p $(OBJ_PATH) 2>/dev/null || true
	@echo "\033[0;32m\n	##### Object files have been removed #####\n\033[0m"

fclean: clean
	@$(RM) $(OBJ) $(NAME)
	@echo "\033[0;32m\n	##### FCLEAN done! #####\n\033[0m"

re: fclean all

.PHONY: all clean fclean re