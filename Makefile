# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 16:58:59 by dmulish           #+#    #+#              #
#    Updated: 2017/10/28 02:04:30 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -I includes/ -g -lm

LIB = libft/libft.a

SRCS = srcs/main.c				\
	   srcs/do_it.c				\
	   srcs/clean_up.c			\
	   srcs/dijkstra.c			\
	   srcs/valid_map.c			\
	   srcs/print_ways.c		\
	   srcs/check_links.c		\
	   srcs/check_rooms.c		\
	   srcs/run_algorithm.c		\
	   srcs/search_way_to_end.c	\

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
