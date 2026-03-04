# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 01:39:17 by pedrohe3          #+#    #+#              #
#    Updated: 2026/02/23 18:53:59 by pedrohe3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 

NAME = libft.a

PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c

PART2 =	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c
CFILES = $(PART1) $(PART2)
OBJECTS = $(CFILES:.c=.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
	ft_lstmap_bonus.c
BONUS_OBJECTS = $(BONUS:.c=.o)

PRINTF = ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putptr_pf.c ft_putnbr_pf.c ft_putnbr_base_pf.c ft_putuint_pf.c ft_puthex_pf.c
PRINTF_OBJECTS = $(PRINTF:.c=.o)

# --- Default rules and dependencies ---
all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: .bonus

.bonus: $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS)
	touch .bonus
	ar -crs $(NAME) $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS)

# --- Control rules ---
clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean bonus
