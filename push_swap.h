/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:03:49 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 15:03:54 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

/*
** NODE STRUCTURE: The building block of our doubly linked list.
** value: The actual integer from input.
** index: The relative rank (0 to N-1), essential for Radix Sort.
** next: Pointer to the element below (towards the bottom).
** prev: Pointer to the element above (towards the top).
*/
typedef struct s_node
{
	int             value;
	int             index;
	struct s_node   *next;
	struct s_node   *prev;
}	t_node;

/*
** STACK STRUCTURE: Keeps track of the stack's boundaries and size.
** top: The first element (where operations like sa, pa, ra happen).
** bottom: The last element (useful for rra and adding elements).
** size: Current number of elements (avoids looping to count).
*/
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* Prototypes for Student A's work */
t_node	*node_new(int value);
t_stack	*init_stack(void);
void	stack_add_back(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);
long	ft_atol(const char *str);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
void	free_split(char **split);
int		parse_arguments(int argc, char **argv, t_stack *stack_a);
double	get_disorder(t_stack *stack);

/* Operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
