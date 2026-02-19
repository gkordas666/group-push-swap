/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:20:48 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 15:46:10 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Creates and returns a new node with the given integer value */
t_node	*node_new(int value)
{
	t_node	*new; // Declare a pointer to the new node

	new = malloc(sizeof(t_node)); // Allocate memory for the node
	if (!new) // If allocation failed
		return (NULL); // Return NULL to signal failure
	new->value = value; // Store the integer value in the node
	new->index = -1; // Index is unknown until Student B runs index_stack()
	new->next = NULL; // No next node yet (will be linked later)
	new->prev = NULL; // No previous node yet (will be linked later)
	return (new); // Return the fully initialized node
}

/* Allocates and returns an empty stack structure */
t_stack	*init_stack(void)
{
	t_stack	*stack; // Declare a pointer to the new stack

	stack = malloc(sizeof(t_stack)); // Allocate memory for the stack
	if (!stack) // If allocation failed
		return (NULL); // Return NULL to signal failure
	stack->top = NULL; // No elements yet, top is empty
	stack->bottom = NULL; // No elements yet, bottom is empty
	stack->size = 0; // Stack starts with zero elements
	return (stack); // Return the empty stack
}

/* Adds a node to the bottom of the stack (used during parsing to preserve order) */
void	stack_add_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node) // If either pointer is NULL
		return ; // Do nothing, avoid segfault
	if (!stack->top) // If the stack is currently empty
	{
		stack->top = new_node; // New node is the first and only top
		stack->bottom = new_node; // New node is also the bottom
	}
	else // Stack already has at least one element
	{
		stack->bottom->next = new_node; // Link current bottom to new node
		new_node->prev = stack->bottom; // Link new node back to current bottom
		stack->bottom = new_node; // Update bottom to point to new node
	}
	stack->size++; // Increment the element counter
}
