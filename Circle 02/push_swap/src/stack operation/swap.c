#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_list		*head;
	t_list		*next;
	t_list		*nnext;

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
	ft_putstr_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack *stackB)
{
	swap(stackB);
	ft_putstr_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	swap(stackA);
	swap(stackB);
	ft_putstr_fd("ss", STDOUT_FILENO);
}
