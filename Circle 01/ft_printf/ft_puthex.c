/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:48 by haile         #+#    #+#                 */
/*   Updated: 2024/11/20 14:27:37 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//hexadecimal - x or X

void	ft_puthex(unsigned int num, char c, int *res)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (c == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (num == 0)
	{
		ft_putchar('0', res);
		return ;
	}
	while (num != 0)
	{
		string[i++] = base_character [num % 16];
		num /= 16;
	}
	while (i--)
		ft_putchar(string[i], res);
}
