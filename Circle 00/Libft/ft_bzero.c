/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:40:56 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:14:04 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//cannot work with *s directly

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore bzero(): %s\n", str);
  
	ft_bzero(str, 0);
  	printf("After bzero():  %s", str);
	return 0;
}
*/
/*
Alternative, could just use ft_memset. Using memset(str,0,n)
Line 24 is actually str = (char*)s
*/
