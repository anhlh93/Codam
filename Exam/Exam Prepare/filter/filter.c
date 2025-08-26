#include <unistd.h> //strncmp
#include <stdlib.h> //malloc
#include <string.h>
#include <stdio.h> //printf

#ifndef BUFFER_SIZE
#define	BUFFER_SIZE 1
#endif

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
	{

		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*/Allowed functions : printf, perror, calloc, malloc, realloc, strlen,
					read, free


*/

int main(int ac, char **av)
{
	if (ac !=2 | av[1][0] == '\0')
		return (1);
	printf("Real strncmp: %d\n", strncmp("hello", "hello123", 5));
	printf("My strncmp: %d\n", ft_strncmp("hello", "hello123", 5));
	return 0;
}
