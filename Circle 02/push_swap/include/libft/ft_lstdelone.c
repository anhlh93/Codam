/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haianhle <haianhle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 07:04:29 by haianhle      #+#    #+#                 */
/*   Updated: 2025/07/08 07:04:30 by haianhle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
