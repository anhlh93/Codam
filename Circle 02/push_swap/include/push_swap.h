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
} t_stack;

typedef struct s_val
{
	int		num;
	int		radix_index;
} t_val;
