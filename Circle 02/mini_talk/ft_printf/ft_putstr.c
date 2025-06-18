/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:54 by haile         #+#    #+#                 */
/*   Updated: 2025/02/21 13:57:12 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//string

void	ft_putstr(char *s, int *res)
{
	size_t	i;
	ssize_t	check;

	i = 0;
	if (!s)
	{
		check = write(1, "(null)", 6);
		if (check == -1)
		{
			*res = -1;
			return ;
		}
		(*res) += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], res);
		i++;
	}
}
