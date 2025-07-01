/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:45:43 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:21:45 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	di;
	size_t	si;

	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	dlen = ft_strlen(dest);
	if (size <= dlen)
		return (slen + size);
	if (size > (dlen + slen))
		size = dlen + slen + 1;
	di = dlen;
	si = 0;
	while (src[si] && di + 1 < size)
	{
		dest[di] = src[si];
		di++;
		si++;
	}
	dest[di] = 0;
	return (slen + dlen);
}
/*
#include "string.h"
#include "stdio.h"
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_print_result(int n)
{
	char	c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}
*/
