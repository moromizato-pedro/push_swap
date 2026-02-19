# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 04:39:18 by pedrohe3          #+#    #+#              #
#    Updated: 2026/02/19 05:14:06 by pedrohe3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

CFILES = push_swap.c push_swap_utils.c
OBJECTS = $(CFILES:.c=.o)

HFILES = push_swap.h

NAME = push_swap
libft = /libft/libft.a

all: $(NAME) 

$(NAME): $(libft) $(OBJECTS) 
	echo $(OBJECTS)

$(libft):
	make -s bonus -C libft

%.o : %.c
	cc $(CFLAGS) $(CFILES) -c -o $@ $^ 

clean:
	make -s clean -C libft
	rm $(OBJECTS)

fclean: clean
	rm $(libft)
	rm push_swap

re: fclean all

.PHONY: all clean fclean
