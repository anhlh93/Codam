CFLAGS	= -Wall -Wextra -Werror -Wunreachable-code
NAME	= push_swap
LIBFT	= include/libft
HEADER	= include/

SRCS	= 	./src/main.c \
			./src/stack_operation/push.c \
			./src/stack_operation/reverse.c \
			./src/stack_operation/rotate.c \
			./src/stack_operation/swap.c \
			./src/sort.c \
			./src/ultis.c \
			./src/ultis2.c \

OBJS	= ${SRCS:.c=.o}

# Compile, default rule.
all: $(NAME)

# To create the .o files, take the .c file and
# use -c to compile or assemble the source file, then -o to output.
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBFT) -O3

# Compile everything, first create the objects.
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a

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
