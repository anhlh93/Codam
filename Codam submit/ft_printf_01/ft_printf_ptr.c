/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:26 by haile         #+#    #+#                 */
/*   Updated: 2025/02/13 11:30:24 by haile         ########   odam.nl         */
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
		write(1, "(nil)", 5);
		(*res) += 5;
		return ;
	}
	i = 0;
	base_character = "0123456789abcdef";
	write(1, "0x", 2);
	(*res) += 2;
	while (ptr != 0)
	{
		string[i++] = base_character[ptr % 16];
		ptr /= 16;
	}
	while (i--)
		ft_putchar(string[i], res);
}
