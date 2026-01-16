# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:59:11 by cbuzzini          #+#    #+#              #
#    Updated: 2026/01/16 17:37:39 by cbuzzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

CXX = c++ 
FLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = brain

all: $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CXX) $(FLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
