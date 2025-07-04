/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:46:12 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:16:33 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		a;

	if (!s1 && !s2)
		return (0);
	i = 0;
	a = 0;
	while (!a && (s1[i] && s2[i]) && (i < n))
	{
		a = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (!a && (s1[i] == '\0' || s2[i] == '\0') && (i < n))
		a = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (a);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	printf("%d", ft_strncmp("HelloWorld","Hello", 6));
	printf("\n%d", strncmp("HelloWorld", "Hello", 6)); 
}
*/
