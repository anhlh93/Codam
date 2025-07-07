/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   full_default_init.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:56:53 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 12:03:27 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_init(t_fractol *f, int starting_pos)
{
	if (starting_pos == 1)
	{
		f->shape.julia.cr = 0.285;
		f->shape.julia.ci = 0;
	}
	else if (starting_pos == 2)
	{
		f->shape.julia.cr = -0.8;
		f->shape.julia.ci = 0.156;
	}
	else if (starting_pos == 3)
	{
		f->shape.julia.cr = -0.4;
		f->shape.julia.ci = 0.6;
	}
	else if (starting_pos == 4)
	{
		f->shape.julia.cr = -0.7;
		f->shape.julia.ci = 0.27015;
	}
}

void	init_shape(t_fractol *f)
{
	f->shape.min_real = -2.5;
	f->shape.max_real = 1.5;
	f->shape.min_imag = -1.5;
	f->shape.max_imag = f->shape.min_imag
		+ (f->shape.max_real - f->shape.min_real) * HEIGHT / WIDTH;
	julia_init(f, f->julia_options);
}

void	struct_init(t_fractol *f)
{
	init_pos(f);
	init_zoom(f);
	init_mlx_utils(f);
	img_struct_init(f);
	init_shape(f);
	f->color_index = 1;
	f->colorama = init_colorama(f, f->color_index);
	if (!f->colorama)
		close_program(f);
	f->max_iter = 75;
}

void	window_init(t_fractol *f)
{
	struct_init(f);
	f->utils.ptr = mlx_init();
	if (!f->utils.ptr)
		close_program(f);
	f->utils.wd = mlx_new_window(f->utils.ptr, WIDTH, HEIGHT, "FRACT'OL");
	if (!f->utils.wd)
		close_program(f);
	f->img.mlx_img = mlx_new_image(f->utils.ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.mlx_img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
}
