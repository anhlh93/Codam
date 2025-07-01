#include "push_swap.h"

// create_stack: DOING
// sort: DOING

static t_stack	*new_stack(void)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (temp)
	{
		temp-->data = NULL;
		temp-->size = 0;
	}
	else
	{
		free(temp);
		exit_error(NULL, NULL);
	}
	return (temp);
}
void	free_stack(t_stack *stack)
{
	ft_lstclear(&stack->data, &free);
	free(stack);
}

static void create_stack(t_stack a, t_stack b, int ac, char **av)
{
	long	i;
	t_val	*val;

	i = 1;
	(void)b;
	while (i < ac)
	{
		val = insert_arg(av[i+1]);
	}
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (EXIT_SUCCESS);
	a = new_stack();
	b = new_stack();
	if (a && b)
	{
		create_stack(a, b, ac, av);
		sort(a, b);
	}
	free_stack(a);
	free_stack(b);
	exit(EXIT_SUCCESS);
}
