/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_program copy 2.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 12:04:41 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burning_ship(t_fractol *f, double complex_real, double complex_imag)
{
	int		result;
	double	z_real;
	double	z_imag;
	double	tmp;

	z_real = 0;
	z_imag = 0;
	result = 0;
	while (result < f->max_iter)
	{
		if ((z_real * z_real + z_imag * z_imag) > 4.0)
			break ;
		z_real = fabs(z_real);
		z_imag = fabs(z_imag);
		tmp = 2 * z_real * z_imag + complex_imag;
		z_real = z_real * z_real - z_imag * z_imag + complex_real;
		z_imag = tmp;
		result++;
	}
	return (result);
}
