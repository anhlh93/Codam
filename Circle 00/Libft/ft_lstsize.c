/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:43:50 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:06:45 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;
	node	*lst;

	node = t_list;
	count = 0;
	while (!node == NULL)
	{
		count++;
		node->next = node;
	}
	return (count);
}
