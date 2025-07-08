/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haianhle <haianhle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 07:05:06 by haianhle      #+#    #+#                 */
/*   Updated: 2025/07/08 07:05:10 by haianhle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (out)
	{
		out->content = content;
		out->next = NULL;
		return (out);
	}
	return (NULL);
}
