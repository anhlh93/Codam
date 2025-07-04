/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:45:13 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:20:39 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (0);
	ft_memcpy(new, s, size);
	new[size] = '\0';
	return (new);
}
/*
int	main()
{
	char	source[] = "GeeksForGeeks";
	char	*target;
       
	target	= strdup(source);
	printf("%s", target);
	return (0);
}
*/
/* 
** GOAL: save a copy of a string
** A copy of source is created dynamically
** and pointer to copy is returned.
*/
