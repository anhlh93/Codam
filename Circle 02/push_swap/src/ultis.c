/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ultis.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 09:10:29 by haile         #+#    #+#                 */
/*   Updated: 2025/07/08 09:10:30 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

// add_arg: DOING
/// check_parsing: DOING

bool	check_parsing(const char *str)
{
	int		minus_count;
	size_t	i;

	i = -1;
	minus_count = 0;
	while (str[++i])
	{
		if (str[i] == '-')
		{
			if (i > 0 && ft_isdigit(str[i - 1]))
				return (false);
			minus_count += 1;
			if (minus_count > 1 || !ft_isdigit(str[i + 1]) || !str[i + 1])
				return (false);
			continue ;
		}
		else if (ft_isdigit(str[i]))
			continue ;
		else
			return (false);
	}
	return (true);
}

t_val	*add_arg(char *c)
{
	long	nbr;
	t_val	*temp;

	if (!*c || !check_parsing(c))
		return (NULL);
	temp = malloc(sizeof(t_val));
	if (!temp)
		return (NULL);
	nbr = ft_atoi(c);
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		return (NULL);
	}
	temp->num = nbr;
	temp->radix_index = -1;
	return (temp);
}

bool	check_sorted(t_stack *stack)
{
	t_list	*c;

	c = stack->data;
	while (c->next)
	{
		if (((t_val *)c->next->content)->num < ((t_val *)c->content)->num)
			return (false);
		c = c->next;
	}
	return (true);
}

t_val	*stack_index(t_stack *stack, int index)
{
	int		i;
	t_list	*c;

	i = 0;
	c = stack->data;
	if (stack->size == 0)
		return (NULL);
	else if (stack->size <= index)
		return ((t_val *)ft_lstlast(stack->data)->content);
	while (i < index && c)
	{
		c = c->next;
		i += 1;
	}
	return ((t_val *)c->content);
}
