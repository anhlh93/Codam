/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:04:55 by haile         #+#    #+#                 */
/*   Updated: 2025/07/08 09:28:18 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char	*str;

	str = "2142";
	printf("FT_ATOI (%s) = %d\n\n", str, ft_atoi(str));
	printf("ATOI (%s) = %d\n\n", str, atoi(str));
	return (0);
}
*/
/* Code explaination
- First loop to eliminate special character such as \t, \n or space
- Next, loop to determine sign of the number (positive or negative)
- Next, loop to create a new number from existing strings of characters.
*/
