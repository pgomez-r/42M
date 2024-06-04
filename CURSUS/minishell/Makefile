# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 21:48:21 by pgomez-r          #+#    #+#              #
#    Updated: 2024/03/01 13:49:42 by pgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
LDFLAGS  = -L /Users/${USER}/.brew/opt/readline/lib -lreadline
INC_RL   = -I /Users/${USER}/.brew/opt/readline/include
NAME     = minishell

SRC_PATH = src/
OBJ_PATH = obj/

SRC      = main.c init.c free.c bi_exit_echo.c lexer.c lexer_utils.c redir.c \
			bi_dir.c bi_utils.c arr_tools_0.c arr_tools_1.c cmd_maker.c \
			cmd_driver.c exegguttor_utils.c cmd_maker_utils.c heredoc.c \
			bi_exp.c manage_input.c quotes.c quotes2.c expand.c mini_utils.c \
			bi_exp_utils.c bi_unset.c expand_utils.c signals.c heredoc_utils.c \
			check_spchar.c syntax_check.c mini_utils_1.c
SRCS	 = $(addprefix $(SRC_PATH), $(SRC))
OBJ		 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

RM       = rm -f

all:	${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_RL) -c $< -o $@
$(NAME):	$(OBJS)
	@echo "\033[0;33m\n	 ##### Checking/compiling Libft_42 library #####\n\033[0m"
	@${MAKE} -C ./inc/libft
	@${CC} $(CFLAGS) $(OBJS) $(LDFLAGS) ./inc/libft/libft.a  -o $(NAME)
	@echo "\033[0;32m\n	 ##### Minishell is ready! #####\n\033[0m"

norm:
		@echo "\033[0;32m\n	 ##### Cheking 42_School_NORMINETTE #####\n\033[0m";
		@norminette src/ inc/libft/
		
debug:
		@gcc -Wall -Wextra -Werror -lreadline ./src/*.c ./inc/libft/libft.a -o debug 
		@echo "\033[0;32m\n	##### Debug file successfully generated #####\n\033[0m"

clean:
		@${RM} ${OBJS}
		@${MAKE} -C ./inc/libft clean
		@echo "\033[0;32m\n	##### Object files have been removed #####\n\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@${MAKE} -C ./inc/libft fclean
		@${RM} debug
		@echo "\033[0;32m\n	##### FCLEAN done! #####\n\033[0m"

re:	fclean all

.PHONY: all clean fclean re debug
