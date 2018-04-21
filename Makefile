SRC_PATH = src/
SRC_NAME = ft_ls.c ls_list.c parser.c tri_list.c ls_print.c display.c\
			display_time.c display_misc.c error.c display_endline.c
OBJ_PATH = obj/
CPPFLAGS = -Iinclude
LDFLAGS = -Llibft
LDLIBS = -lft
NAME = ft_ls
CC = clang
CFLAG = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)

re: fclean libfclean all

lib:
	make -C libft

libfclean:
	make -C libft fclean

.PHONY: all, clean, fclean, re