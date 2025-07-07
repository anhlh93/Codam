# include "push_swap.h"

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
	ft_putstr_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stack *b)
{
	reverse(b);
	ft_putstr_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr", STDOUT_FILENO);
}
