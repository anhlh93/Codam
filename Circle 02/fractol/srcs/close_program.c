/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_program.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 11:59:18 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_program(t_fractol *f)
{
	if (f->img.mlx_img)
		mlx_destroy_image(f->utils.ptr, f->img.mlx_img);
	if (f->utils.wd)
		mlx_destroy_window(f->utils.ptr, f->utils.wd);
	if (f->utils.ptr)
		mlx_destroy_display(f->utils.ptr);
	if (f->utils.ptr)
		free(f->utils.ptr);
	if (f->colorama)
		free(f->colorama);
	exit(0);
}
