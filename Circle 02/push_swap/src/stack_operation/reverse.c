# include "push_swap.h"

void	get_last(t_stack *stack, t_list **slast, t_list **last)
{
	t_list	*iter;

	if (!stack || !stack->data || !stack->data->next)
	{
		*slast = NULL;
		*last = NULL;
		return;
	}
	iter = stack->data;
	while (iter)
	{
		if (!iter->next->next)
		{
			(*slast) = iter;
			(*last) = iter->next;
			break ;
		}
		iter = iter->next;
	}
}

/**
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack The Stack.
 */
static void	reverse(t_stack *stack)
{
	t_list	*slast;
	t_list	*last;

	slast = NULL;
	last = NULL;
	get_last(stack, &slast, &last);
	slast->next = NULL;
	ft_lstadd_front(&stack->data, last);
}

void	rra(t_stack *a)
{
	reverse(a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack *b)
{
	reverse(b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

