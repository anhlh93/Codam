# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: haile <haile@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2025/06/18 12:06:14 by haile         #+#    #+#                  #
#    Updated: 2025/07/02 01:43:42 by haianhle      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c
SRC_PRINTF = ft_printf/ft_printf_nbr.c \
             ft_printf/ft_printf_ptr.c \
             ft_printf/ft_printf.c \
             ft_printf/ft_puthex.c \
             ft_printf/ft_putstr.c

# Define object files for each component
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(SERVER) $(CLIENT)

# Build server from object files
$(SERVER): $(OBJ_SERVER) $(OBJ_PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(OBJ_PRINTF)

# Build client from object files
$(CLIENT): $(OBJ_CLIENT) $(OBJ_PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(OBJ_PRINTF)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_PRINTF)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
