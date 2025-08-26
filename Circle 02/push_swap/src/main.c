/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 09:09:38 by haile         #+#    #+#                 */
/*   Updated: 2025/07/08 09:27:15 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*new_stack(void)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (temp)
	{
		temp->size = 0;
		temp->data = NULL;
	}
	else
		exit_error(NULL, NULL);
	return (temp);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	ft_lstclear(&stack->data, &free);
	free(stack);
}

static void	create_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	long	i;
	t_val	*val;

	i = 1;
	(void)b;
	while (i < ac)
	{
		val = add_arg(av[i]);
		if (!val)
			exit_error(a, b);
		if (is_dup(a, val->num))
		{
			free(val);
			exit_error(a, b);
		}
		ft_lstadd_back(&a->data, ft_lstnew(val));
		i++;
	}
	a->size = i - 1;
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
		if (ac == 2)
		{
			create_stack_from_split(a, b, av[1]);
		}
		else
			create_stack(a, b, ac, av);
		sort(a, b);
	}
	free_stack(a);
	free_stack(b);
	exit(EXIT_SUCCESS);
}
