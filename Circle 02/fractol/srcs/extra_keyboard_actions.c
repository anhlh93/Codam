/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 15:00:29 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 11:57:10 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_fractal(t_fractol *f)
{
	init_shape(f);
	init_zoom(f);
	f->fractal++;
	if (f->fractal == 4)
		f->max_iter = 10;
	if (f->fractal > 4)
	{
		f->max_iter = 100;
		f->fractal = 1;
	}
}

void	change_color(t_fractol *f)
{
	f->color_index++;
	free(f->colorama);
	f->colorama = init_colorama(f, f->color_index);
	if (!f->colorama)
		close_program(f);
	if (f->color_index > 3)
		f->color_index = 0;
}

void	change_julia_set(t_fractol *f)
{
	init_shape(f);
	init_zoom(f);
	f->julia_options++;
	if (f->julia_options > 4)
		f->julia_options = 1;
}
