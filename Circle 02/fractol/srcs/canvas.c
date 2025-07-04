/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 15:00:29 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:00:40 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->win = mlx_new_window(canvas->mlx, WIDTH, HEIGHT, CANVAS_TITLE);
	if (canvas->win == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->img.img = mlx_new_image(canvas->mlx, WIDTH, HEIGHT);
	if (canvas->img.img == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img,
			&canvas->img.bits_per_pixel, &canvas->img.line_length,
			&canvas->img.endian);
	canvas->comp_info.max.re = 2;
	canvas->comp_info.max.im = 2;
	canvas->comp_info.min.re = -2;
	canvas->comp_info.min.im = -2;
	canvas->comp_info.c.re = 0.4;
	canvas->comp_info.c.im = -0.325;
	canvas->is_pressed_mouse_left = false;
	canvas->max_iter = MAX_ITER;
}
