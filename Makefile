CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

SRC_DIR	= src
SRC = colors.c errors.c exit.c fdf.c gradients.c hooks.c instructions.c map.c pixel.c points.c\

OBJ_DIR	= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ./include
INCLUDE = fdf.h keys.h

MAIN = src/main.c

LIBFT = ./libft/libft.a
LIBS = -lmlx -lXext -lX11 -lm

NAME = fdf

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@echo "Compiling fdf..."
	@$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)
	@echo "\033[1;32mDone."

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft

clean:
	@$(RM) $(OBJ_DIR)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all