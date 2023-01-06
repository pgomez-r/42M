# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:51:47 by pgomez-r          #+#    #+#              #
#    Updated: 2023/01/06 17:09:13 by pgruz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE    = push_swap
LIB    = push_swap.h
SRCS   = main.c ps_utils.c libft_utils.c split_atoi.c arg_check.c
OBJS   = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(EXE) : $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(EXE)

%.o : %.c
	gcc -c $(CFLAGS) -g $< -o $@

clean:
	rm -f *.o

fclean:
	rm -f *.o $(EXE)

re: fclean $(EXE)

.PHONY: clean fclean re