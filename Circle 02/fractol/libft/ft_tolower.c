/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:46:42 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:12:35 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, tolower(c));
	c = 'D';
	printf("\n%c -> %c", c, tolower(c));
	c = '9';
	printf("\n%c -> %c", c, tolower(c));
	c = 'm';
	printf("\n%c -> %c", c, ft_tolower(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_tolower(c));
	c = '9';
	printf("\n%c -> %c", c, ft_tolower(c));
	return (0);
}
*/
