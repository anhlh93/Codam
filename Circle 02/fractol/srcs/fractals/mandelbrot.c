/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 14:17:10 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_fractol *f, double complex_real, double complex_imag)
{
	int		res;
	double	z_real;
	double	z_imag;
	double	tmp;

	z_real = 0;
	z_imag = 0;
	res = -1;
	while (++res < f->max_iter)
	{
		if ((z_real * z_real + z_imag * z_imag) > 4.0)
			break ;
		tmp = 2 * z_real * z_imag + complex_imag;
		z_real = z_real * z_real - z_imag * z_imag + complex_real;
		z_imag = tmp;
	}
	return (res);
}
