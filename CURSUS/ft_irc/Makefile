NAME		= ircserv
CC			= g++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror -I./inc

SRC_PATH	= src/
OBJ_PATH	= obj/

SRC			= main utils Server Server_init Server_utils Server_channel \
				User User_init Channel Channel_init \
				Command_cmds Command_init Command_mode Command_login Command_join \
				Command_response

SRCS		= $(addsuffix .cpp, $(addprefix $(SRC_PATH), $(SRC))) \

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
