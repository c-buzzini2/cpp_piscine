# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:59:11 by cbuzzini          #+#    #+#              #
#    Updated: 2026/02/17 13:05:13 by cbuzzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE_DIR = includes/

SRC_FILES = main.cpp \
			AMateria.cpp \
			Cure.cpp \
			Ice.cpp
			
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

CXX = c++ 
FLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = Materia

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HDR_FILES_ALL)
	$(CXX) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	$(CXX) $(FLAGS) $(OBJ_FILES) -I$(INCLUDE_DIR) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
