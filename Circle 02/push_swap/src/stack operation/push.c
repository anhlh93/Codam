#include "push_swap.h"

static void push(t_stack *to, t_stack *from)
{
	t*list temp;

	temp = from->data->next;
	ft_lstadd_front(&to->data, from->data);
	from->data = temp;
}
void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	b->size -= 1;
	a->size += 1;
	ft_printf("pa");
}
void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	a->size -= 1;
	b->size += 1;
	ft_printf("pb");
}

