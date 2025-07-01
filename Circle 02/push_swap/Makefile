CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
LIBFT	= include/libft
PRINTF	= include/ft_printf
HEADER	= include/

SRCS	= ./src/handle.c \
			./src/main.c \
			./src/operations/push.c \
			./src/operations/reverse.c \
			./src/operations/rotate.c \
			./src/operations/swap.c \
			./src/sort.c \
			./src/utils/utils.c \

OBJS	= ${SRCS:.c=.o}

# Compile, default rule.
all: $(NAME)

# To create the .o files, take the .c file and
# use -c to compile or assemble the source file, then -o to output.
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBFT) -I $(PRINTF) -O3

# Compile everything, first create the objects.
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(PRINTF)/libftprintf.z

# Clean object files
clean:
	rm -f $(OBJS)

# Clean library file
fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

# Re-compile
re:	fclean all

# Phonies as not to confuse make, these are actual commands, not files.
.PHONY: all, clean, fclean, re
