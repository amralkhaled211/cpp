NAME	= megaphone

CXX		= c++

CXXFLGAS	= -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : megaphone.cpp
	$(CXX) $(CXXFLGAS) megaphone.cpp -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : clean all

.PHONY : all clean fclean re