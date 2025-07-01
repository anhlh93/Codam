/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:50:46 by haile         #+#    #+#                 */
/*   Updated: 2025/03/03 11:14:28 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(int fd, char *line)
{
	char	*buffer;
	char	*temp;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(line), free(buffer), NULL);
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(line, buffer);
		if (temp == NULL)
			return (free(buffer), NULL);
		line = temp;
	}
	return (free(buffer), line);
}

char	*ft_get_next_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*update(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (free(line), NULL);
	j = -1;
	while (line[++i])
		str[++j] = line[i];
	str[++j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;	

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	line = extract_line(fd, line);
	if (!line)
		return (NULL);
	next_line = ft_get_next_line(line);
	if (next_line == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = update(line);
	return (next_line);
}
