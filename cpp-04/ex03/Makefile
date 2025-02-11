# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 11:30:45 by xroca-pe          #+#    #+#              #
#    Updated: 2025/02/11 18:23:41 by xroca-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphismInterface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
INCLUDES = AMateria.hpp ICharacter.hpp Ice.hpp Cure.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp
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