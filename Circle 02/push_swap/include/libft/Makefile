# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: haile <haile@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2024/11/06 10:47:13 by haile         #+#    #+#                  #
#    Updated: 2024/11/06 13:25:50 by haile         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Sources files compile for first and second part
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
       ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_lstclear.c
# Object files compile for first and second part
OBJS = ${SRCS:.c=.o}
# Sources files compile for bonus part
SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c
# Object files compile for bonus part
OBJSB = ${SRCSB:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
LIBC = ar rcs
RM = rm -f

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
