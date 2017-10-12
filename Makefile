# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 16:58:59 by dmulish           #+#    #+#              #
#    Updated: 2017/10/12 19:03:43 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -I includes/ -g

LIB = libft/libft.a

SRCS = srcs/main.c	\

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -j4 -C libft/

$(NAME): $(BINS) $(LIB)
	gcc -o $(NAME) $(FLAGS) $(BINS) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
