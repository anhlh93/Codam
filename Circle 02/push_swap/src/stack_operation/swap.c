/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 09:11:04 by haile         #+#    #+#                 */
/*   Updated: 2025/07/08 09:11:08 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_list	*head;
	t_list	*next;
	t_list	*nnext;

	if (stack->size > 1)
	{
		head = stack->data;
		next = head->next;
		nnext = next->next;
		stack->data = next;
		stack->data->next = head;
		stack->data->next->next = nnext;
	}
}

void	sa(t_stack *stackA)
{
	swap(stackA);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack *stackB)
{
	swap(stackB);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	swap(stackA);
	swap(stackB);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
