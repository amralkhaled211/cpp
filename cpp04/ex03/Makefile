NAME	= Interface

SRC	= AMateria.cpp ICharacter.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJ	= $(SRC:.cpp=.o)

CC	= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re