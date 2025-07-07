/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 14:16:52 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	random_double_real(void)
{
	static unsigned long	seed = 123456789;
	double					random;

	seed = (1103515245 * seed + 12345) % 2147483648;
	random = ((double)seed) / 2147483648.0;
	random = random * 1.5 - 1.0;
	return (random);
}

double	random_double_imag(void)
{
	static unsigned long	seed = 123456789;
	double					random;

	seed = (1103515245 * seed + 12345) % 2147483648;
	random = ((double)seed) / 2147483648.0;
	return (random);
}

void	julia_random_values(t_fractol *f)
{
	f->shape.julia.cr = random_double_real();
	f->shape.julia.ci = random_double_imag();
}

int	julia(t_fractol *f, double z_real, double z_imag)
{
	int		res;
	double	tmp;

	res = -1;
	while (++res < f->max_iter)
	{
		if ((z_real * z_real + z_imag * z_imag) > 4.0)
			break ;
		tmp = 2 * z_real * z_imag + f->shape.julia.ci;
		z_real = z_real * z_real - z_imag * z_imag + f->shape.julia.cr;
		z_imag = tmp;
	}
	return (res);
}
