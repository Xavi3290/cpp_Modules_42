# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 19:38:20 by xavi              #+#    #+#              #
#    Updated: 2025/02/06 18:05:02 by xroca-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = globalBanksters

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = tests.cpp Account.cpp 
INCLUDES = Account.hpp 
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
