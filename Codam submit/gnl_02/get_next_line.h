/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:50:51 by haile         #+#    #+#                 */
/*   Updated: 2025/02/21 12:55:10 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "unistd.h"
# include "stdlib.h"
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#   define MAX_FD 1024  // Common maximum number of file descriptors

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*extract_line(int fd, char *line);
char	*ft_strjoin(char *line, char *buff);
char	*ft_get_next_line(char *line);
char	*new_line(char *line);
char	*get_next_line(int fd);

#endif
