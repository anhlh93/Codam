# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: haile <haile@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2024/11/06 14:50:02 by haile         #+#    #+#                  #
#    Updated: 2024/11/06 14:52:50 by haile         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Sources files compile for mandatory part
SRCS = ft_printf.c ft_putstr.c\
	ft_printf_nbr.c ft_puthex.c\
	ft_printf_ptr.c

# Object files compile for mandatory part
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBC = ar rcs
RM = rm -f

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
