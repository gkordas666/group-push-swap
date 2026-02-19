/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:40:19 by misasant          #+#    #+#             */
/*   Updated: 2026/02/17 12:41:12 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Internal logic to move the top node from 'src' stack to 'dest' stack */
static void	push(t_stack *dest, t_stack *src)
{
	t_node	*node_to_move; // Pointer to the node being moved

	if (!src || src->size == 0) // If source is NULL or empty
		return ; // Nothing to push, do nothing
	node_to_move = src->top; // Save pointer to the top node of source
	src->top = src->top->next; // Move source top to the next node
	if (src->top) // If source still has elements
		src->top->prev = NULL; // New top has no previous node
	else // Source is now empty
		src->bottom = NULL; // Update bottom to NULL as well
	src->size--; // Decrement source size counter
	node_to_move->next = dest->top; // Link moved node to current dest top
	if (dest->top) // If destination already has elements
		dest->top->prev = node_to_move; // Link old dest top back to moved node
	else // Destination was empty
		dest->bottom = node_to_move; // Moved node is also the bottom
	dest->top = node_to_move; // Update dest top to the moved node
	dest->size++; // Increment destination size counter
}

/* pa: Push the top element of stack B to the top of stack A */
void	pa(t_stack *a, t_stack *b)
{
	push(a, b); // Move top of B to top of A
	write(1, "pa\n", 3); // Print the operation name to stdout
}

/* pb: Push the top element of stack A to the top of stack B */
void	pb(t_stack *a, t_stack *b)
{
	push(b, a); // Move top of A to top of B
	write(1, "pb\n", 3); // Print the operation name to stdout
}
