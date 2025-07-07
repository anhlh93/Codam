#include "../include/push_swap.h"

void	exit_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
bool	is_dup(t_stack *stack, int n)
{
	t_list	*iter;

	if (!stack)
		return (false);
	iter = stack -> data;
	while (iter)
	{
		if (n == ((t_val *)iter->content)->num)
			return (true);
		iter = iter->next;
	}
	return (false);
}
