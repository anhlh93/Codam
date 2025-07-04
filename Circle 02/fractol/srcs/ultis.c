/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ultis.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:58:10 by haile         #+#    #+#                 */
/*   Updated: 2025/07/04 15:04:40 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (len > INT_MAX)
	{
		write(fd, str, INT_MAX);
		str += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, str, len);
}

double	abs_double(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

double	squared(double num)
{
	return (num * num);
}
