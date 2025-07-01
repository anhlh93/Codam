/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:46:05 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:25:42 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: Applies the function ’f’ to each character of the
** string ’s’, and passing its index as first argument
** to create a new string (with malloc(3)) resulting
** from successive applications of ’f’.
** Param. #1 The string on which to iterate
** Param. #2 The function to apply to each character.
** Return value The  string created from the successive applications of
** f. Returns NULL if the allocation fails.
** External functions malloc(3)
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
** Special case: s not exist
** str[i] = f(i, s[i]) <-- because unsigned int, char
** malloc: create new string with length using ft_strlen
*/
/*
char my_func(unsigned int i, char str)
{
	printf("My inner function: index = %d and %c\n", i, str);
	return str - 32;
}

int	main()
{
	char str[10] = "hello.";
	printf("The result is %s\n", str);
	char *result = ft_strmapi(str, my_func);
	printf("The result is %s\n", result);
	return 0;
}
*/
