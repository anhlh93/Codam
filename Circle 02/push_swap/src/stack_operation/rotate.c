#include "push_swap.h"

/** 
 * Shift up all elements of stack a by 1. 
 * The first element becomes the last one.
 * @param stack The Stack.
 */
static void	rotate(t_stack *stack)
{
	t_list	*head;
	t_list	*copy;

	copy = stack->data;
	head = stack->data->next;
	stack->data->next = NULL;
	stack->data = head;
	ft_lstadd_back(&head, copy);
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putendl("ra");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putendl("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl("rr");
}