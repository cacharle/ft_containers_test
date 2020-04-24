# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/24 20:21:03 by charles           #+#    #+#              #
#    Updated: 2020/04/24 21:36:04 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_CONTAINERS_DIR = ../ft_containers

NAME = ft_containers_test

CXX = clang++
CXXFLAGS = -Wall -Wextra -I$(FT_CONTAINERS_DIR)

SRC = main.cpp vector_test.cpp log.cpp
OBJ = $(SRC:.cpp=.o)
INC = ft_containers_test.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ)

%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
