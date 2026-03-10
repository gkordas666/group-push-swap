NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

# Paths
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

# Source files
SRC_FILES = adaptive.c	main.c		operations_push.c    rev_rotate.c \
		bench.c		medium.c	operations_rotate.c  simple.c \
		complex.c	medium_utils.c	operations_swap_a.c  stack_init.c \
		get_disorder.c	normalize.c	parsing.c	     swap_util.c


OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Includes
INCLUDES    = -I. -I$(LIBFT_DIR)

# Libraries
LIBS        = -L$(LIBFT_DIR) -lft

####

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "✅ push_swap ready!"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Objects cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️  push_swap removed."

re: fclean all

.PHONY: all clean fclean re
