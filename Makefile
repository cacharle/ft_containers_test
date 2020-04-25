# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/24 20:21:03 by charles           #+#    #+#              #
#    Updated: 2020/04/25 09:42:31 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_CONTAINERS_DIR = ../ft_containers

NAME = ft_containers_test

CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Wextra -I$(FT_CONTAINERS_DIR)

SRC = main.cpp vector_test.cpp log.cpp
OBJ = $(SRC:.cpp=.o)
INC = ft_containers_test.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ)

vector_test.o: vector_test.cpp $(INC) $(FT_CONTAINERS_DIR)/Vector.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
