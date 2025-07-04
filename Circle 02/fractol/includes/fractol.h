/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:17 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:17:26 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364
# define MOVE_RATIO 0.01

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 500

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 3

# define CANVAS_TITLE "Max's Fractol"
# define INVALID_ARG_MSG "Please select fractal type\n \
0: mandelbrot, 1: julia, 2: burning ship\n"

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_complex_num
{
	double			re;
	double			im;
}					t_complex_num;

typedef struct s_complex_info
{
	t_complex_num	z;
	t_complex_num	c;
	t_complex_num	delta;
	t_complex_num	max;
	t_complex_num	min;
}					t_complex_info;

typedef struct s_canvas
{
	void			*mlx;
	void			*win;
	int				max_iter;
	bool			is_pressed_mouse_left;
	char			fractal_type;
	t_img			img;
	t_complex_info	comp_info;
}					t_canvas;

typedef uint32_t	(*t_get_color_func)(t_canvas *);

// draw.c
void				draw_mandelbrot(t_canvas *canvas);
void				draw_julia(t_canvas *canvas);
void				draw_burning_ship(t_canvas *canvas);

// color.c
uint32_t			convert_rgb_hex(int r, int g, int b);
uint32_t			simple_colorizer(int iter, t_canvas *canvas);

// ultis.c
void				ft_putstr_fd(char *str, int fd);
double				abs_double(double val);
double				squared(double num);

// key_hooks.c
int					exit_canvas(int exit_code);
int					key_press_hook(int keycode, t_canvas *canvas);
int					key_release_hook(int keycode, t_canvas *canvas);

// mouse_hooks.c
int					mouse_press_hook(int button, int x, int y,
						t_canvas *canvas);
int					mouse_release_hook(int button, int x, int y,
						t_canvas *canvas);

// canvas.c
void				init_canvas(t_canvas *canvas);

#endif