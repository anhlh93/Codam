/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:44:27 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:10:28 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		*(str + i) = c;
		i++;
	}
	return (str);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.
	ft_memset(str + 13, '.', 8*sizeof(char));
  	printf("After memset():  %s", str);
	return 0;
}
*/
