#include <unistd.h> //strncmp
#include <stdlib.h> //malloc
#include <string.h>
#include <stdio.h> //printf

#ifndef BUFFER_SIZE
#define	BUFFER_SIZE 10
#endif



/*/Allowed functions : printf, perror, calloc, malloc, realloc, strlen,
					read, free
*/

void	search_and_replace(char *line, char *str)
{
	if (!line || !str || strlen(line) < strlen(str))
		return ;
	int i;
	int j;
	int match;

	i = 0;
	while (line[i])
	{
		j = 0;
		match = 1;
		while (str[j])
		{
			if (line[i + j] != str[j])
			{
				match = 0;
				break;
			}
			j++;
		}
		if (match)
		{
			j = 0;
			while (str[j])
			{
				line[i + j] = '*';
				j++;
			}
			i += j;
		}
		else
			i++;
	}
}

int main(int ac, char **av)
{
	if (ac !=2 | av[1][0] == '\0')
		return (1);
	char	line[70000];
	char	buffer[BUFFER_SIZE];
	int	line_pos = 0;
	int	byte_rd = 0;
	int	i;

	while (1)
	{
		byte_rd = read(0, buffer, BUFFER_SIZE);
		if (byte_rd < 0)
		{
			perror("Error: ");
			return (1);
		}
		if (byte_rd == 0)
			break;
		i = 0;
		while (byte_rd > i)
		{
			if (buffer[i] == '\n')
			{
				line[line_pos] = '\0';
				search_and_replace(line, av[1]);
				printf("%s\n", line);
				line_pos = 0;
			}
			else
			{
				line[line_pos] = buffer[i];
				line_pos++;
			}
			i++;
		}
	}
	return (0);
}
