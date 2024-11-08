/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:41:16 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:14:01 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb && total_size / nmemb != size)
		return (NULL);
	a = (void *)malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (nmemb * size));
	return (a);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	int	i;
	int	n;
	int	*a;

	printf("Number of elements to be entered:");
	scanf("%d",&n);
	a = (int *)ft_calloc(n, sizeof(int));
	printf("Enter %d numbers: \n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("The numbers entered are: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	free(a);
	return (0);
}
*/
