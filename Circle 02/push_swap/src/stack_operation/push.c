#include "push_swap.h"

static void push(t_stack *to, t_stack *from)
{
	t_list *temp;

	temp = from->data->next;
	ft_lstadd_front(&to->data, from->data);
	from->data = temp;
}
void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	b->size -= 1;
	a->size += 1;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}
void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	a->size -= 1;
	b->size += 1;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

