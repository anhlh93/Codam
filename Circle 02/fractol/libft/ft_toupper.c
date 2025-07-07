/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:46:49 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:12:37 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, toupper(c));
	c = 'D';
	printf("\n%c -> %c", c, toupper(c));
	c = '9';
	printf("\n%c -> %c", c, toupper(c));
	c = 'm';
	printf("\n%c -> %c", c, ft_toupper(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_toupper(c));
	c = '9';
	printf("\n%c -> %c", c, ft_toupper(c));
	return (0);
}
*/
