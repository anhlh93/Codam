/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:50:36 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:06:04 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_fractal_color(t_canvas *canvas)
{
	int				iteration;
	double			tmp_x;
	t_complex_info	c_info;

	iteration = 0;
	c_info = canvas->comp_info;
	while (squared(c_info.z.re) + squared(c_info.z.im) <= 4)
	{
		tmp_x = squared(c_info.z.re) - squared(c_info.z.im) + c_info.c.re;
		if (canvas->fractal_type != '2')
			c_info.z.im = 2 * c_info.z.re * c_info.z.im + c_info.c.im;
		else
		{
			c_info.z.im = abs_double((double)2 * c_info.z.re * c_info.z.im)
				+ c_info.c.im;
		}
		c_info.z.re = tmp_x;
		iteration++;
		if (iteration == canvas->max_iter)
			return (convert_rgb_hex(0, 0, 0));
	}
	return (simple_colorizer(iteration, canvas));
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_canvas *canvas)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &canvas->comp_info;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_info->z.re = 0;
			c_info->z.im = 0;
			c_info->c.im = c_info->min.im + y * c_info->delta.im;
			c_info->c.re = c_info->min.re + x * c_info->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_fractal_color(canvas));
			x++;
		}
		y++;
	}
}

void	draw_julia(t_canvas *canvas)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &canvas->comp_info;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_info->z.im = c_info->min.im + y * c_info->delta.im;
			c_info->z.re = c_info->min.re + x * c_info->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_fractal_color(canvas));
			x++;
		}
		y++;
	}
}

void	draw_burning_ship(t_canvas *canvas)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &canvas->comp_info;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_info->z.re = 0;
			c_info->z.im = 0;
			c_info->c.im = c_info->min.im + y * c_info->delta.im;
			c_info->c.re = c_info->min.re + x * c_info->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_fractal_color(canvas));
			x++;
		}
		y++;
	}
}
