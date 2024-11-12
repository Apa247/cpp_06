# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 18:47:02 by daparici          #+#    #+#              #
#    Updated: 2024/11/12 18:47:22 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	

vpath                   %.hpp include
vpath                   %.cpp src
vpath                   %.o obj

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
PURPLE		=	\033[35m
UP			=	\033[A
CUT			=	\033[K

INCLUDE         =   -Iinclude/
SRC = main.cpp  .cpp
OBJ_DIR = obj

CC = c++
SANITIZER       =   -g3 -fsanitize=address -g
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) $(SANITIZER)

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

RM = rm -f

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	$(CC) $(CPPFLAGS) -c $< -o $@
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"


all: $(NAME)
	@printf "\n"
	@printf "$(BLUE)  ____    _     ____    _    ____   ___   ___  ___  \n$(RESET)"
	@printf "$(BLUE) |  _ \  / \   |  _ \  / \  |  _ \ |_ _| / __||_ _| \n$(RESET)"
	@printf "$(YELLOW) | | | |/ _ \  | |_) |/ _ \ | |_) | | | | |    | |  \n$(RESET)"
	@printf "$(RED) | |_| / ___ \ |  __// ___ \|  _ <  | | | |__  | |  \n$(RESET)"
	@printf "$(GREEN) |____/_/   \_\|_|  /_/   \_\_| \_\|___| \___||___| \n$(RESET)"
	@printf "$(GREEN)                                                    \n$(RESET)"
	@printf "\n"

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(PURPLE)Finished [$(NAME)]$(RESET)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(RED)Deleting all objects from /ex01...$(RESET)"; else \
	echo "No objects to remove from /ex01."; \
	fi;



fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(RED)Deleting $(NAME) from /ex01...$(RESET)"; else \
	echo "No Executable to remove from /ex01."; \
	fi;
	


re: fclean all

.PHONY: all clean fclean re