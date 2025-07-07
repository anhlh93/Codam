/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:13 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 12:49:22 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_2(t_fractol *f, char *av)
{
	if (ft_strncmp(av, "mandelbrot", 15) == 0)
	{
		f->julia_options = 1;
		f->fractal = MANDELBROT;
		return (1);
	}
	else if (ft_strncmp(av, "julia", 15) == 0)
	{
		f->fractal = JULIA;
		f->julia_options = 1;
		return (1);
	}
	else if (ft_strncmp(av, "burning ship", 15) == 0)
	{
		f->julia_options = 1;
		f->fractal = BURNING;
		return (1);
	}
	return (0);
}

int	check_3(t_fractol *f, char *av1, char *av2)
{
	int	n;

	n = ft_atoi(av2);
	if (ft_strncmp(av1, "julia", 15) == 0 && (n >= 1 && n <= 4))
	{
		f->fractal = JULIA;
		if (n == 1)
			f->julia_options = 1;
		else if (n == 2)
			f->julia_options = 2;
		if (n == 3)
			f->julia_options = 3;
		if (n == 4)
			f->julia_options = 4;
		return (1);
	}
	return (0);
}

int	parsing_arg(t_fractol *f, int ac, char **av)
{
	if (ac == 2 && check_2(f, av[1]))
		return (1);
	if (ac == 3 && check_3(f, av[1], av[2]))
		return (1);
	return (0);
}

void	show_messages(void)
{
	ft_putstr_fd(PARAM_ERROR, 1);
	ft_putstr_fd(PARAM_EXAMPLE, 1);
	ft_putstr_fd(P_EX_LIST, 1);
	ft_putstr_fd(JULIA_OPTIONS, 1);
	ft_putstr_fd(JULIA_EXAMPLE, 1);
}
