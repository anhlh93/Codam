/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haianhle <haianhle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 07:04:25 by haianhle      #+#    #+#                 */
/*   Updated: 2025/07/08 07:04:27 by haianhle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}
