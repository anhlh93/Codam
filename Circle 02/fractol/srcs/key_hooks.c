/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:13 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:03:37 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_canvas(int exit_code)
{
	exit(exit_code);
}

static void	move_arrow_key_2(int keycode, t_canvas *canvas)
{
	t_complex_num	*max;
	t_complex_num	*min;
	double			offset;

	max = &canvas->comp_info.max;
	min = &canvas->comp_info.min;
	offset = max->re - min->re;
	if (keycode == KEY_RIGHT_ARROW)
	{
		min->re += offset * MOVE_RATIO;
		max->re += offset * MOVE_RATIO;
	}
	if (keycode == KEY_LEFT_ARROW)
	{
		min->re -= offset * MOVE_RATIO;
		max->re -= offset * MOVE_RATIO;
	}
}

static void	move_arrow_key_1(int keycode, t_canvas *canvas)
{
	t_complex_num	*max;
	t_complex_num	*min;
	double			offset;

	max = &canvas->comp_info.max;
	min = &canvas->comp_info.min;
	offset = max->im - min->im;
	if (keycode == KEY_UP_ARROW)
	{
		min->im -= offset * MOVE_RATIO;
		max->im -= offset * MOVE_RATIO;
	}
	if (keycode == KEY_DOWN_ARROW)
	{
		min->im += offset * MOVE_RATIO;
		max->im += offset * MOVE_RATIO;
	}
	move_arrow_key_2(keycode, canvas);
}

int	key_press_hook(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESC)
		exit_canvas(EXIT_SUCCESS);
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW
		|| keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		move_arrow_key_1(keycode, canvas);
	return (0);
}
