# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 01:16:20 by nhaquet           #+#    #+#              #
#    Updated: 2016/04/14 20:20:35 by nhaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_PATH = .
SRC_NAME = ft_ls.c
OBJ_PATH = obj
MAKE = make
CC = clang
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./
LDLIBS = -lft
LDFLAGS = -Llibft/
RM = rm -f
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ).o: $(SRC).c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all
