/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 09:27:33 by haile         #+#    #+#                 */
/*   Updated: 2025/07/08 09:27:58 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdbool.h>

// DOING: t_val; functions

/* TYPES */

typedef struct s_stack
{
	t_list	*data;
	int		size;
}			t_stack;

typedef struct s_val
{
	int		num;
	int		radix_index;
}			t_val;

/* FUNCTIONS */

t_val		*add_arg(char *c);
bool		check_parsing(const char *str);
bool		check_sorted(t_stack *stack);
void		exit_error(t_stack *a, t_stack *b);
bool		is_dup(t_stack *stack, int n);
void		free_stack(t_stack *stack);
void		sort(t_stack *a, t_stack *b);
void		sort_3(t_stack *a);
void		sort_5(t_stack *a, t_stack *b);
void		radix_sort(t_stack *a, t_stack *b);
t_val		*stack_index(t_stack *stack, int index);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *a, t_stack *b);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		print_stack(t_stack *stack);
void		get_last(t_stack *stack, t_list **slast, t_list **last);

#endif
