NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

# Paths
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

# Source files (Noms EXACTS de ton dossier src/)
SRC_FILES   = main.c \
              stack_init.c \
              parsing.c \
              get_disorder.c \
              operations_swap_a.c \
              operations_push.c \
              operations_rotate.c \
              rev_rotate.c \
              swap_util.c

OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Includes (On ajoute . pour trouver push_swap.h à la racine)
INCLUDES    = -I. -I$(LIBFT_DIR)

# Libraries
LIBS        = -L$(LIBFT_DIR) -lft

###############################################################################

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
