/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:44:15 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:07:12 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	while (i < n)
	{
		*(char *)(s1 + i) = *(char *)(s2 + i);
		i++;
	}
	return (s1);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int	arr1[5] = {1, 2, 3, 4, 5};
	int	arr2[5];
	int arr3[5];
	size_t	i;

	ft_memcpy(arr2, arr1, sizeof(int) * 3);
	memcpy(arr3, arr1, sizeof(int) * 3);
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr2[i]);
		printf("%d ", arr3[i]);
		i++;
	}
	//printf("%d", ft_memcpy("HelloWorld","Hello", 6));
	//printf("\n%d", memcpy("HelloWorld", "Hello", 6)); 
}
*/
