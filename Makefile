# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 16:58:59 by dmulish           #+#    #+#              #
#    Updated: 2017/10/22 14:42:53 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -I includes/ -g

LIB = libft/libft.a

SRCS = srcs/main.c			\
	   srcs/valid_map.c		\
	   srcs/check_links.c	\
	   srcs/check_rooms.c	\

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -j4 -C libft/
	gcc -o $(NAME) $(FLAGS) $(BINS) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIB)

re: fclean all
