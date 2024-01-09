# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = checker
LIBFT = ../libft/libft.a
CHECKER_SRC = main.c clean_bonus.c asc_mod_bonus.c asc_int_bonus.c \
				ope_r_bonus.c ope_rr_bonus.c ope_s_p_bonus.c
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
INCLUDES_DIR = -I../includes -I../libft
#pas necessaire parceque -lft -lmlx dans la ligne cc
# Default rule
all: $(NAME)

# This won't be called if the files don't exist or are not updated
$(CHECKER_OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

$(LIBFT):
	make -C ../libft

$(NAME): $(LIBFT) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $(NAME) -L../libft -lft

clean:
	make clean -C ../libft
	rm -f $(CHECKER_OBJ)

fclean: clean
	make fclean -C ../libft
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re run