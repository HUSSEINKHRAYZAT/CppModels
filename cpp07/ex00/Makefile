
SRC  = $(wildcard *.cpp)
NAME = temp

all: $(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)

clean:
	@echo "Nothing to clean (no .o files created)."

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
