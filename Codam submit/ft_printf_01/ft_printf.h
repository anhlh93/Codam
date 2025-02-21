/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 14:49:42 by haile         #+#    #+#                 */
/*   Updated: 2024/11/20 14:27:34 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "unistd.h"
# include "stdlib.h"

void		ft_putchar(char c, int *res);
void		ft_putstr(char *s, int *res);
void		ft_putptr(size_t ptr, int *res);
void		ft_put_uint(unsigned int nb, int *res);
int			ft_printf(const char *format, ...);
void		ft_putnbr(int n, int *res);
void		ft_puthex(unsigned int num, char c, int *res);

#endif
