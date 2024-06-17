NAME	= DiamondTrap

SRC	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp  DiamondTrap.cpp

OBJ	= $(SRC:.cpp=.o)

CC	= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

all: $(NAME)

$(NAME): $(OBJ) ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re