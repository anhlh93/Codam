/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_hooks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:14:20 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:04:21 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	magnify(double start, double end, double ratio)
{
	return (start + (end - start) * ratio);
}

static void	zoom_canvas(t_canvas *canvas, int button, int x, int y)
{
	double			mouse_re;
	double			mouse_im;
	double			magnification;
	t_complex_info	*c_info;

	magnification = 0.0;
	mouse_re = (double)x / (WIDTH / (c_info->max.re - c_info->min.re))
		+ c_info->min.re;
	mouse_im = (double)y / (HEIGHT / (c_info->max.im - c_info->min.im))
		+ c_info->min.im;
	if (button == SCROLL_UP)
	{
		if (canvas->max_iter > 4)
			canvas->max_iter = canvas->max_iter - 4;
		magnification = 100 / 80;
	}
	else
	{
		canvas->max_iter = canvas->max_iter + 4;
		magnification = 100 / 120;
	}
	c_info->min.re = magnify(mouse_re, c_info->min.re, magnification);
	c_info->min.im = magnify(mouse_im, c_info->min.im, magnification);
	c_info->max.re = magnify(mouse_re, c_info->max.re, magnification);
	c_info->max.im = magnify(mouse_im, c_info->max.im, magnification);
}

int	mouse_press_hook(int button, int x, int y, t_canvas *canvas)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_canvas(canvas, button, x, y);
	else if (button == MOUSE_LEFT_BUTTON)
		canvas->is_pressed_mouse_left = true;
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_canvas *canvas)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_BUTTON)
		canvas->is_pressed_mouse_left = false;
	return (0);
}
