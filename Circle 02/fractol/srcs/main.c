/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:03:50 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_fractal(t_canvas *canvas)
{
	int				x;
	int				y;
	double			mouse_re;
	double			mouse_im;
	t_complex_info	*c_info;

	c_info = &canvas->comp_info;
	mlx_mouse_get_pos(canvas->mlx, canvas->win, &x, &y);
	mouse_re = (double)x / (WIDTH / (c_info->max.re - c_info->min.re))
		+ c_info->min.re;
	mouse_im = (double)y / (HEIGHT / (c_info->max.im - c_info->min.im)) * -1
		+ c_info->max.im;
	c_info->c.re = mouse_re;
	c_info->c.im = mouse_im;
}

int	draw_fractal(t_canvas *canvas)
{
	if (canvas->is_pressed_mouse_left)
		update_fractal(canvas);
	if (canvas->fractal_type == '0')
		draw_mandelbrot(canvas);
	else if (canvas->fractal_type == '1')
		draw_julia(canvas);
	else if (canvas->fractal_type == '2')
		draw_burning_ship(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_canvas	canvas;

	if (ac != 2 || (!av[1][0] == '0' || !av[1][0] == '1' || !av[1][0] == '2'
			|| !av[1][1] == '\0'))
	{
		ft_putstr_fd(INVALID_ARG_MSG, STDOUT_FILENO);
		return (1);
	}
	canvas.fractal_type = av[1][0];
	init_canvas(&canvas);
	mlx_hook(canvas.win, ClientMessage, 1L << 17, exit_canvas, &canvas);
	mlx_hook(canvas.win, KeyPress, KeyPressMask, key_press_hook, &canvas);
	mlx_mouse_hook(canvas.win, mouse_press_hook, &canvas);
	mlx_hook(canvas.win, ButtonRelease, ButtonReleaseMask, mouse_release_hook,
		&canvas);
	mlx_loop_hook(canvas.mlx, &draw_fractal, &canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
