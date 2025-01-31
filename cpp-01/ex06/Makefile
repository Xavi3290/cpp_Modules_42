# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 18:32:21 by xavi              #+#    #+#              #
#    Updated: 2025/01/31 19:16:53 by xavi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address
SRCS = main.cpp Harl.cpp 
INCLUDES = Harl.hpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re