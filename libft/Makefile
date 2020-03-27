# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 10:40:45 by tlee              #+#    #+#              #
#    Updated: 2020/02/28 17:04:16 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./src/*.c

Object = *.o

Header = -I ./includes

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(Header) $(SRC)
	ar rc $(NAME) $(Object)
	ranlib $(NAME)

clean:
	/bin/rm -f $(Object)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
