#include "../include/push_swap.h"

static void	create_index(t_stack *s)
{
	int	i;
	t_list	*cpy;
	t_val	*smallest;

	i = 0;
	while (i < s->size)
	{
		smallest = NULL;
		cpy = s->data;
		while (cpy)
		{
			if (((t_val *)cpy->content)->radix_index > -1)
			{
				cpy = cpy->next;
				continue ;
			}
			else if (!smallest || ((t_val *)cpy->content)->num < smallest->num)
				smallest = ((t_val *)cpy->content);
			cpy = cpy->next;
		}
		smallest->radix_index = i;
		i++;
	}
}

void sort_3(t_stack *a)
{
	int	an;
	int	bn;
	int	cn;

	an = stack_index(a, 0)->num;
	bn = stack_index(a, 1)->num;
	cn = stack_index(a, 2)->num;
	if (an > bn && bn < cn && cn > an)
		sa(a);
	else if (an > bn && bn > cn && cn < an)
	{
		sa(a);
		rra(a);
	}
	else if (an > bn && bn < cn && cn < an)
		ra(a);
	else if (an < bn && bn > cn && cn > an)
	{
		sa(a);
		ra(a);
	}
	else if (an < bn && bn > cn && cn < an)
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size != 3)
	{
		if (stack_index(a, 0)->radix_index <= 1)
			pb(a, b);
		else
			rra(a);
	}
	sort_3(a);
	while (b->size > 0)
	{
		if (stack_index(a, 0)->radix_index < stack_index(b, 0)->radix_index)
		{
			pa(a, b);
			sa(a);
		}
		else
			pa(a, b);
	}
}
static void	big_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	size;

	i = 0;
	index = 0;
	size = a->size;
	while (!check_sorted(a))
	{
		i = -1;
		while (++i < size)
		{
			if ((((t_val *)a->data->content)->radix_index >> index) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		index++;
	}
}

void sort(t_stack *a, t_stack *b)
{
	if (check_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (stack_index(a, 0)->num > stack_index(a, 1)->num)
			sa(a);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
	{
		create_index(a);
		sort_5(a, b);
	}
	else
	{
		create_index(a);
		big_sort(a, b);
	}
}
