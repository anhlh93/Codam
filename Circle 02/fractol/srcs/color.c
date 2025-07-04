/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                             :+:    :+:           */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:56:53 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:02:48 by haile          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	convert_rgb_hex(int r, int g, int b)
{
	uint32_t	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

uint32_t	simple_colorizer(int iter, t_canvas *canvas)
{
	int	a;

	a = (int)((double)iter / canvas->max_iter * 255);
	return (convert_rgb_hex(a, a, a));
}
