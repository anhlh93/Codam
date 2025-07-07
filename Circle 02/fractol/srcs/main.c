/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 13:11:30 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (parsing_arg(&fractol, ac, av))
	{
		print_guide();
		window_init(&fractol);
		render(&fractol);
		event_management(&fractol);
		mlx_loop(fractol.utils.ptr);
	}
	else
		show_messages();
	return (0);
}
