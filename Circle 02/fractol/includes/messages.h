/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   messages.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:17 by haile         #+#    #+#                 */
/*   Updated: 2025/07/07 12:11:13 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* *** show_controls *** */

# define PARAM_ERROR "\nPlease add one parameter to ./fractol.\n"
# define PARAM_EXAMPLE "\nExample : (Lowercase only) ./fractol mandelbrot\n"
# define P_EX_LIST "\nOptions:\n\n- mandelbrot\n- julia\n- burning ship\n"
# define JULIA_OPTIONS "\nFor Julia, you can add a number between 1 and 4.\n"
# define JULIA_EXAMPLE "\nExample : ./fractol julia 3\n"
# define ENJOY "\nEnjoy exploration!\n\n"

/* *** print_controls *** */

# define MOVES "\nPress Up / a, Down / b, Left / a or Right / d to navigate.\n\n"
# define ZOOOM "Scroll up / down to zoom in & out at pointer x / y.\n\n"
# define ITER "Press space to iterate + 5 or go -5 with b.\n\n"
# define JUL "Press r to give random coords to Julia or j for set options.\n\n"
# define CH "Press x to switch between fractals, press c to switch colors.\n\n"
# define ESC "Press esc or click on the X of the window when done.\n\n"

#endif