/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:26 by haile         #+#    #+#                 */
/*   Updated: 2024/12/06 14:37:17 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//pointer

void	ft_putptr(size_t ptr, int *res)
{
	char	string[25];
	char	*base_character;
	int		i;

	i = 0;
	base_character = "0123456789abcdef";
	write(1, "0x", 2);
	(*res) += 2;
	if (ptr == 0)
	{
		ft_putchar('0', res);
		return ;
	}
	while (ptr != 0)
	{
		string[i++] = base_character[ptr % 16];
		ptr /= 16;
	}
	while (i--)
		ft_putchar(string[i], res);
}
