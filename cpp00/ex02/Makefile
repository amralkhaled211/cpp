NAME	= Account

SRCS	= tests.cpp Account.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) Account.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re