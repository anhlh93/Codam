# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: haile <haile@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2025/06/18 12:06:14 by haile         #+#    #+#                  #
#    Updated: 2025/06/18 12:23:22 by haile         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRC_SERVER = server.c

SRC_CLIENT = client.c

SRC_PRINTF =	ft_printf/ft_printf_nbr.c\
				ft_printf/ft_printf_ptr.c\
				ft_printf/ft_printf.c\
				ft_printf/ft_puthex.c\
				ft_printf/ft_putstr.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm - rfv

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ)
		$(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER) $(SRC_PRINTF)

$(CLIENT): $(OBJ)
		$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT) $(SRC_PRINTF)
		
clean:
	$(RM) $(OBJ)
	
fclean:
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re