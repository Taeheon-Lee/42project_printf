NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SOURCE = source/*.c libft/src/*.c
OBJECT = *.o
INCLUDE = .

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SOURCE) -I $(INCLUDE)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@rm -f ./libft/*.o

fclean: clean
	@rm -f $(NAME) ./libft/libft.a

re: fclean all
