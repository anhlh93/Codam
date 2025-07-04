#include "../includes/fractol.h"

//NEED TO RESEARCH: (7 function) parsing_arg, print_control, window_init; render; event_management; mlx_loop; show_options
int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (parsing_arg(&fractol, ac, av))
	{
		print_controls();
		window_init(&fractol);
		render(&fractol);
		event_management(&fractol);
		mlx_loop(fractol.utils.ptr);
	}
	else
		show_options();
	return (0);
}
