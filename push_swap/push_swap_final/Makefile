# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:51:47 by pgomez-r          #+#    #+#              #
#    Updated: 2023/05/04 21:15:52 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BNAME   = bonus_checker

SRCS   = arg_check.c libft_utils.c lis_utils.c main.c operations_db.c \
			operations_maker.c operations_ps.c operations_rot.c ps_utils_b.c \
			ps_utils.c sort_complex.c sort_easy.c split_atoi.c

BSRCS  = bonus/arg_check.c bonus/get_next_line_utils.c bonus/get_next_line.c \
			bonus/libft_utils.c bonus/main.c bonus/operations_db.c \
			bonus/operations_ps.c bonus/operations_rot.c bonus/ps_utils.c \
			bonus/split_atoi.c
			
OBJS   = $(SRCS:.c=.o)

BOBJS   = $(BSRCS:.c=.o)

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

RM     = rm -f

all:	${NAME}

$(NAME):	$(OBJS)
	${CC} $(CFLAGS) $(OBJS) -o $(NAME)

bonus:	$(BOBJS)
		${CC} $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
		${RM} ${OBJS} ${BOBJS}

fclean:	clean
		${RM} ${NAME} ${BNAME}

re:	fclean all bonus

.PHONY: all bonus clean fclean re