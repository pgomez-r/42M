# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:51:47 by pgomez-r          #+#    #+#              #
#    Updated: 2023/01/26 17:08:06 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE    = push_swap
LIB    = push_swap.h
SRCS   = arg_check.c libft_utils.c main.c operations_db.c operations_ps.c \
			operations_rot.c ps_utils.c split_atoi.c sort_easy.c
OBJS   = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(EXE) : $(OBJS)
	gcc $(CFLAGS) -g $(OBJS) -o $(EXE)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean:
	rm -f *.o $(EXE)

re: fclean $(EXE)

.PHONY: clean fclean re