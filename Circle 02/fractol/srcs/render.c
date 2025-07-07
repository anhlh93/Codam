/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:14:20 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 12:02:18 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pix_put(t_ima *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	pix_calculate(t_fractol *f, double real, double imag)
{
	if (f->fractal == MANDELBROT)
		return (mandelbrot(f, real, imag));
	if (f->fractal == JULIA)
		return (julia(f, real, imag));
	if (f->fractal == BURNING)
		return (burning_ship(f, real, imag));
	else
		return (0);
}

void	render(t_fractol *f)
{
	double	real;
	double	imag;
	int		pix;

	mlx_clear_window(f->utils.ptr, f->utils.wd);
	f->pos.y = 0;
	while (f->pos.y <= HEIGHT)
	{
		f->pos.x = 0;
		while (f->pos.x <= WIDTH)
		{
			real = f->shape.min_real + (double)f->pos.x
				* (f->shape.max_real - f->shape.min_real) / WIDTH;
			imag = f->shape.max_imag + (double)f->pos.y
				* (f->shape.min_imag - f->shape.max_imag) / HEIGHT;
			pix = pix_calculate(f, real, imag);
			if (pix == f->max_iter)
				pix_put(&f->img, f->pos.x, f->pos.y, COLOR24);
			else
				pix_put(&f->img, f->pos.x, f->pos.y, f->colorama[pix % COLORS]);
			f->pos.x++;
		}
		f->pos.y++;
	}
	mlx_put_image_to_window(f->utils.ptr, f->utils.wd, f->img.mlx_img, 0, 0);
}
