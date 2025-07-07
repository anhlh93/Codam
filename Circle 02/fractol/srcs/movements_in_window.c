/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements_in_window.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:50:36 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 17:19:40 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	magnify(double start, double end, double magnification)
{
	double	offset;

	offset = end - start;
	return (start + (offset * magnification));
}
int	mouse_event_management(int button, int x, int y, t_fractol *f)
{
	double	magnification = 0.0;
	double	mouse_re;
	double	mouse_im;
	
	mouse_re = (double)x / WIDTH * (f->shape.max_real - f->shape.min_real)
		+ f->shape.min_real;
	mouse_im = (double)y / HEIGHT * (f->shape.max_imag - f->shape.min_imag)
		+ f->shape.min_imag;
	if (button == SCROLL_UP)
	{
		if (f->max_iter > 4)
			f->max_iter -= 4;
		magnification = 1.0 /0.95;
	}
	else if (button == SCROLL_DOWN)
	{
		f->max_iter += 4;
		magnification = 1.0 /1.05;
	}
	f->shape.min_real = magnify(mouse_re, f->shape.min_real, magnification);
	f->shape.max_real = magnify(mouse_re, f->shape.max_real, magnification);
	f->shape.min_imag = magnify(mouse_im, f->shape.min_imag, magnification);
	f->shape.max_imag = magnify(mouse_im, f->shape.max_imag, magnification);
	render(f);
	return (0);
}

// void	zoom(t_fractol *f, double zoom)
// {
// 	f->zoom.new_real = f->shape.min_real - f->shape.max_real;
// 	f->zoom.new_imag = f->shape.max_imag - f->shape.min_imag;
// 	f->shape.max_real = f->shape.max_real + (f->zoom.new_real - zoom
// 			* f->zoom.new_real) / 2;
// 	f->shape.min_real = f->shape.max_real + zoom * f->zoom.new_real;
// 	f->shape.min_imag = f->shape.min_imag + (f->zoom.new_imag - zoom
// 			* f->zoom.new_imag) / 2;
// 	f->shape.max_imag = f->shape.min_imag + zoom * f->zoom.new_imag;
// }

// void	move(t_fractol *f, double move, int direction)
// {
// 	f->zoom.new_imag = f->shape.max_imag - f->shape.min_imag;
// 	f->zoom.new_real = f->shape.min_real - f->shape.max_real;
// 	if (direction == MOVE_UP)
// 	{
// 		f->shape.min_imag += f->zoom.new_imag * move;
// 		f->shape.max_imag += f->zoom.new_imag * move;
// 	}
// 	else if (direction == MOVE_LEFT)
// 	{
// 		f->shape.min_real += f->zoom.new_real * move;
// 		f->shape.max_real += f->zoom.new_real * move;
// 	}
// 	else if (direction == MOVE_RIGHT)
// 	{
// 		f->shape.max_real -= f->zoom.new_real * move;
// 		f->shape.min_real -= f->zoom.new_real * move;
// 	}
// 	else if (direction == MOVE_DOWN)
// 	{
// 		f->shape.max_imag -= f->zoom.new_imag * move;
// 		f->shape.min_imag -= f->zoom.new_imag * move;
// 	}
// }

// int	mouse_event_management(int button, int x, int y, t_fractol *f)
// {
// 	if (button == MOUSE_W_UP)
// 	{
// 		if (f->fractal <= 3)
// 			f->max_iter += 5;
// 		zoom(f, MOUSE_ZOOM);
// 		x -= WIDTH / 2;
// 		y -= HEIGHT / 2;
// 		if (x < 0)
// 			move(f, (double)abs_value(x) / WIDTH, MOVE_LEFT);
// 		else if (x > 0)
// 			move(f, (double)x / WIDTH, MOVE_RIGHT);
// 		if (y < 0)
// 			move(f, (double)abs_value(y) / HEIGHT, MOVE_UP);
// 		else if (y > 0)
// 			move(f, (double)y / HEIGHT, MOVE_DOWN);
// 	}
// 	else if (button == MOUSE_W_DOWN)
// 	{
// 		if (f->fractal <= 3)
// 			f->max_iter -= 5;
// 		zoom(f, ZOOM_OUT);
// 	}
// 	render(f);
// 	return (0);
// }

// int	keyboard_movements(int key, t_fractol *f)
// {
// 	if (key == XK_Up || key == XK_w)
// 		move(f, MOVE_DISTANCE, MOVE_UP);
// 	else if (key == XK_Right || key == XK_d)
// 		move(f, MOVE_DISTANCE, MOVE_RIGHT);
// 	else if (key == XK_Left || key == XK_a)
// 		move(f, MOVE_DISTANCE, MOVE_LEFT);
// 	else if (key == XK_Down || key == XK_s)
// 		move(f, MOVE_DISTANCE, MOVE_DOWN);
// 	render(f);
// 	return (0);
// }
