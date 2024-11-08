/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:45:07 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:26:24 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	str[] = "http://www.tutorialspoint.com";
	const char	ch = 'w';
	char	*ret;

	ret = ft_strchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
}
*/
// Locate character in string
