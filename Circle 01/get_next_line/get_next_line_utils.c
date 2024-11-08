/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:50:41 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 14:52:49 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while ((char)c != *s && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*new;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	new = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (!new)
		return (NULL);
	while (line)
		*new++ = *line++;
	while (buff)
		*new++ = *buff++;
	*new = '\0';
	free(line);
	return (new);
}
