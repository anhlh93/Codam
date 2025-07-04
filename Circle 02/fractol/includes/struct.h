#ifndef FRACTOL_H
# define FRACTOL_H

/* ************************************************************************** */
/*                                STRUCTURES                                  */
/* ************************************************************************** */

/*
** MLX Image Management
** Handles all MLX image-related data and properties
*/
typedef struct s_image
{
	void	*mlx_img;		/* MLX image pointer */
	char	*addr;			/* Image data address */
	int		bpp;			/* Bits per pixel */
	int		line_len;		/* Line length in bytes */
	int		endian;			/* Endianness flag */
}	t_image;

/*
** Position Coordinates
** Stores x,y coordinates for window positioning
*/
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

/*
** MLX Utilities
** Core MLX pointers for display and window management
*/
typedef struct s_mlx
{
	void	*ptr;			/* MLX instance pointer */
	void	*window;		/* Window pointer */
}	t_mlx;

/*
** Complex Number
** Mathematical representation of complex numbers (a + bi)
*/
typedef struct s_complex
{
	double	real;			/* Real part */
	double	imag;			/* Imaginary part */
}	t_complex;

/*
** Fractal Boundaries
** Defines the mathematical boundaries and Julia set parameters
*/
typedef struct s_boundaries
{
	double		min_real;		/* Minimum real value */
	double		max_real;		/* Maximum real value */
	double		min_imag;		/* Minimum imaginary value */
	double		max_imag;		/* Maximum imaginary value */
	t_complex	julia_param;	/* Julia set constant */
}	t_boundaries;

/*
** Zoom Management
** Handles zoom calculations and transformations
*/
typedef struct s_zoom
{
	double	scale;			/* Current zoom scale */
	double	offset_x;		/* X-axis offset */
	double	offset_y;		/* Y-axis offset */
}	t_zoom;

/*
** Lyapunov Fractal Data
** Specialized data for Lyapunov fractal calculations
*/
typedef struct s_lyapunov
{
	t_complex	param_a;		/* Parameter A */
	t_complex	param_b;		/* Parameter B */
	t_complex	temp;			/* Temporary calculation value */
	double		lyapunov_exp;	/* Lyapunov exponent */
	char		*sequence;		/* Growth rate sequence */
	int			seq_length;		/* Sequence length */
	int			result;			/* Final calculation result */
}	t_lyapunov;

/*
** Main Fractol Structure
** Central data structure containing all fractal rendering information
*/
typedef struct s_fractol
{
	/* Core components */
	t_position		pos;			/* Current cursor position */
	t_mlx			mlx;			/* MLX utilities */
	t_image			img;			/* Image data */
	t_boundaries	bounds;			/* Mathematical boundaries */
	t_zoom			zoom;			/* Zoom management */

	/* Fractal-specific data */
	t_lyapunov		lyapunov;		/* Lyapunov fractal data */

	/* Rendering parameters */
	int				fractal_type;	/* Fractal type identifier */
	int				max_iterations;	/* Maximum iteration limit */
	int				julia_preset;	/* Julia set preset option */

	/* Color management */
	int				*color_palette;	/* Color palette array */
	int				color_offset;	/* Current color offset */
}	t_fractol;

/* ************************************************************************** */
/*                              FRACTAL TYPES                                */
/* ************************************************************************** */

# define MANDELBROT		1
# define JULIA			2
# define BURNING_SHIP	3
# define LYAPUNOV		4

/* ************************************************************************** */
/*                               CONSTANTS                                   */
/* ************************************************************************** */

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define MAX_ITER		100

#endif
