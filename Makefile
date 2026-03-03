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
SRC_FILES   = main.c \
              stack_init.c \
              parsing.c \
              get_disorder.c \
              operations_swap_a.c \
              operations_push.c \
              operations_rotate.c \
              rev_rotate.c \
              swap_util.c \
              adaptive.c \
              complex.c \
              medium.c \
              medium_utils.c \
              normalize.c \
              simple.c

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
