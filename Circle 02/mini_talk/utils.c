/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haianhle <haianhle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 01:22:34 by haianhle      #+#    #+#                 */
/*   Updated: 2025/07/02 11:52:53 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

char	*ft_charjoin(char *s1, char s2)
{
	int		size;
	int		i;
	char	*new;

	i = 0;
	size = 0;
	while (s1 && s1[size])
		size++;
	new = malloc(sizeof(char) * (size + 2));
	if (new == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = s2;
	new[i] = '\0';
	free(s1);
	return (new);
}
