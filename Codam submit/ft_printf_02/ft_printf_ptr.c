/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:26 by haile         #+#    #+#                 */
/*   Updated: 2025/02/21 14:06:22 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//pointer

void	ft_putptr(size_t ptr, int *res)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (ptr == 0)
	{
		ft_putstr("(nil)", res);
		return ;
	}
	i = 0;
	base_character = "0123456789abcdef";
	ft_putstr("0x", res);
	while (ptr != 0)
	{
		string[i++] = base_character[ptr % 16];
		ptr /= 16;
	}
	while (i--)
		ft_putchar(string[i], res);
}
