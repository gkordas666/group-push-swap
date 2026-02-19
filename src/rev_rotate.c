/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:15:09 by misasant          #+#    #+#             */
/*   Updated: 2026/02/19 14:17:56 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Moves the bottom node to the top of the stack.
** Before: top -> [1] [2] [3] <- bottom
** After:  top -> [3] [1] [2] <- bottom
*/
static void	rev_rotate(t_stack *stack)
{
	t_node	*first; // The current top node
	t_node	*before_last; // The node just before the bottom
	t_node	*last; // The current bottom node (will move to top)

	if (!stack || stack->size < 2) // If stack is NULL or has less than 2 elements
		return ; // Cannot reverse rotate, do nothing
	first = stack->top; // Save pointer to current top
	last = stack->bottom; // Save pointer to current bottom
	before_last = last->prev; // Save pointer to the node before bottom
	before_last->next = NULL; // Detach last from the list (new bottom has no next)
	last->prev = NULL; // Last node has no previous (it will be the new top)
	last->next = first; // Link last node to the current top
	first->prev = last; // Link current top back to last node
	stack->top = last; // Update stack top to the old bottom
	stack->bottom = before_last; // Update stack bottom to the node before old bottom
}

/* rra: Reverse rotate stack A (bottom goes to top) */
void	rra(t_stack *a)
{
	rev_rotate(a); // Perform reverse rotation on stack A
	write(1, "rra\n", 4); // Print the operation name to stdout
}

/* rrb: Reverse rotate stack B (bottom goes to top) */
void	rrb(t_stack *b)
{
	rev_rotate(b); // Perform reverse rotation on stack B
	write(1, "rrb\n", 4); // Print the operation name to stdout
}

/* rrr: Reverse rotate both stacks simultaneously */
void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a); // Perform reverse rotation on stack A
	rev_rotate(b); // Perform reverse rotation on stack B
	write(1, "rrr\n", 4); // Print the operation name to stdout (only once)
}
