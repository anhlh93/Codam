/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 14:58:13 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	tur_to_navy(int *col)
{
	col[0] = COLOR0;
	col[1] = COLOR1;
	col[2] = COLOR2;
	col[3] = COLOR3;
	col[4] = COLOR4;
	col[5] = COLOR5;
	col[6] = COLOR6;
	col[7] = COLOR7;
	col[8] = COLOR8;
	col[9] = COLOR9;
}

void	white_to_purple_dark(int *col)
{
	col[0] = COLOR23;
	col[1] = COLOR22;
	col[2] = COLOR21;
	col[3] = COLOR20;
	col[4] = COLOR19;
	col[5] = COLOR18;
	col[6] = COLOR17;
	col[7] = COLOR16;
	col[8] = COLOR15;
	col[9] = COLOR14;
}

void	yellow_to_orange(int *col)
{
	col[0] = YO_0;
	col[1] = YO_1;
	col[2] = YO_2;
	col[3] = YO_3;
	col[4] = YO_4;
	col[5] = YO_5;
	col[6] = YO_6;
	col[7] = YO_7;
	col[8] = YO_8;
	col[9] = YO_9;
}

void	rainbow(int *col)
{
	col[0] = RC0;
	col[1] = RC1;
	col[2] = RC2;
	col[3] = RC3;
	col[4] = RC4;
	col[5] = RC5;
	col[6] = RC6;
	col[7] = RC7;
	col[8] = RC8;
	col[9] = RC9;
}

int	*init_color(t_fractol *f, int n)
{
	int	*col;

	col = calloc(sizeof(int), COLORS);
	if (!col)
	{
		close_program(f);
		return (NULL);
	}
	if (n == 1)
		tur_to_navy(col);
	else if (n == 2)
		white_to_purple_dark(col);
	else if (n == 3)
		yellow_to_orange(col);
	else if (n == 4)
		rainbow(col);
	return (col);
}
