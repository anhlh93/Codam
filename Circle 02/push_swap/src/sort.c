//DOING: check_sorted; get_a; sa; index_stack; sort_5

void sort(t_stack *a, t_stack *b)
{
	if (check_sorted(a))
		return ;
	if (a->size == 2)
	{
		if get_a(a, 0)->num > get_a(a, 1)->num)
			sa(a);
	}
	else if (a->size == 3)
		sort3(a);
	else if (a->size <=5)
	{
		index_stack(a);
		sort5(a, b);
	}
	else
	{
		index_stack(a);
		big_sort(a, b)
	}
}
