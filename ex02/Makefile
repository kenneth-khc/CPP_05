# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 19:03:22 by kecheong          #+#    #+#              #
#    Updated: 2025/01/06 00:35:14 by kecheong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := tests

CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic

srcs := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp
objs := $(addprefix obj/, $(srcs:.cpp=.o))

.PHONY: all
all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) $(objs) -o $(NAME)

obj/%.o: %.cpp | obj
	$(CXX) $(CXXFLAGS) $< -c -o $@

obj:
	@mkdir -p obj/

.PHONY: clean
clean:
	$(RM) -r obj/

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g3
debug: $(NAME)

.PHONY: fsan
fsan: CXXFLAGS += -fsanitize=address -g3
fsan: $(NAME)
