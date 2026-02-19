/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:56:34 by misasant          #+#    #+#             */
/*   Updated: 2026/02/17 13:56:36 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Moves the top node to the bottom of the stack.
** Before: top -> [1] [2] [3] <- bottom
** After:  top -> [2] [3] [1] <- bottom
*/
static void	rotate(t_stack *stack)
{
	t_node	*first; // The current top node (will move to bottom)
	t_node	*second; // The node after top (will become new top)
	t_node	*last; // The current bottom node

	if (!stack || stack->size < 2) // If stack is NULL or has less than 2 elements
		return ; // Cannot rotate, do nothing
	first = stack->top; // Save pointer to current top
	second = first->next; // Save pointer to the node after top
	last = stack->bottom; // Save pointer to current bottom
	stack->top = second; // Update stack top to the second node
	second->prev = NULL; // New top has no previous node
	last->next = first; // Link current bottom to the old top
	first->prev = last; // Link old top back to current bottom
	first->next = NULL; // Old top is now the last node, no next
	stack->bottom = first; // Update stack bottom to the old top
}

/* ra: Rotate stack A (top goes to bottom) */
void	ra(t_stack *a)
{
	rotate(a); // Perform rotation on stack A
	write(1, "ra\n", 3); // Print the operation name to stdout
}

/* rb: Rotate stack B (top goes to bottom) */
void	rb(t_stack *b)
{
	rotate(b); // Perform rotation on stack B
	write(1, "rb\n", 3); // Print the operation name to stdout
}

/* rr: Rotate both stacks simultaneously */
void	rr(t_stack *a, t_stack *b)
{
	rotate(a); // Perform rotation on stack A
	rotate(b); // Perform rotation on stack B
	write(1, "rr\n", 3); // Print the operation name to stdout (only once)
}
