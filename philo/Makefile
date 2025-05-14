# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 15:59:59 by pvitor-l          #+#    #+#              #
#    Updated: 2025/05/14 19:24:19 by pvitor-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3
DIR = src
FILES = $(DIR)/main.c \
	$(DIR)/utils.c \
	$(DIR)/init.c \
	$(DIR)/threads.c \
	$(DIR)/actions.c \
	$(DIR)/clear_and_time.c

OBS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBS)
	$(CC) $(CFLAGS) $(OBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBS)

fclean: clean
	rm -f $(NAME)

re: fclean all
