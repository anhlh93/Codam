/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: haianhle <haianhle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 13:27:26 by haianhle      #+#    #+#                 */
/*   Updated: 2025/07/01 13:27:31 by haianhle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!*lst)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	ft_lstdelone((*lst), del);
	(*lst) = NULL;
}
