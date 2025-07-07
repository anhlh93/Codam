/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:10 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 15:01:37 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_pos(t_fractol *f)
{
	f->pos.x = 0;
	f->pos.y = 0;
}

void	init_zoom(t_fractol *f)
{
	f->zoom.new_real = 0;
	f->zoom.new_imag = 0;
}

void	init_mlx_utils(t_fractol *f)
{
	f->utils.ptr = NULL;
	f->utils.wd = NULL;
}

void	img_struct_init(t_fractol *f)
{
	f->img.bpp = 0;
	f->img.line_len = 0;
	f->img.endian = 0;
	f->img.mlx_img = NULL;
	f->img.addr = NULL;
}

int	abs_value(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
