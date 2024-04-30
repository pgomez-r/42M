# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:21:04 by pgomez-r          #+#    #+#              #
#    Updated: 2024/04/30 19:05:49 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Zombie.hpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)
re: fclean all

.PHONY: all clean fclean re