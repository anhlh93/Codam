/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_nbr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:15 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 14:53:13 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//number

void	ft_putnbr(int n, int *res)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*res) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', res);
		ft_putnbr(n * (-1), res);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, res);
		ft_putchar(n % 10 + '0', res);
	}
}

//unsigned int

void	ft_put_uint(unsigned int nb, int *res)
{
	if (nb >= 10)
		ft_put_uint(nb / 10, res);
	ft_putchar(nb % 10 + '0', res);
}
