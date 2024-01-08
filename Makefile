# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
LIBFT = libft/libft.a
PUSH_SWAP_SRC = main.c asc_int.c clean.c atoi_mod.c ope_s_p.c utils.c \
				ope_r.c ope_rr.c algo.c move_b.c small_a.c stack_utils.c \
				rota_a.c rota_b.c calculus.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
#INCLUDES_DIR = -I./includes -I./libft/includes -I./minilibx_macos/includes
#pas necessaire parceque -lft -lmlx dans la ligne cc
# Default rule
all: $(NAME)

# This won't be called if the files don't exist or are not updated
$(PUSH_SWAP_OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT) -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(PUSH_SWAP_OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re run