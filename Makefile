# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 15:59:59 by pvitor-l          #+#    #+#              #
#    Updated: 2025/04/26 17:01:57 by pvitor-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
DIR = src
FILES = $(DIR)/main.c

OBS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBS)
	@$(CC) $(CFLAGS) $(OBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBS)

fclean: clean
	rm -f $(NAME)

re: fclean all
