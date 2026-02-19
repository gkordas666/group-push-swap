/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:41:38 by misasant          #+#    #+#             */
/*   Updated: 2026/02/17 13:19:37 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the values and indexes of the top two nodes.
** We swap VALUES, not pointers, to keep the linked list structure intact.
*/
static void	swap(t_stack *stack)
{
	int	temp_val; // Temporary storage for the top node's value
	int	temp_idx; // Temporary storage for the top node's index

	if (!stack || stack->size < 2) // If stack is NULL or has less than 2 elements
		return ; // Cannot swap, do nothing
	temp_val = stack->top->value; // Save top node's value
	temp_idx = stack->top->index; // Save top node's index
	stack->top->value = stack->top->next->value; // Copy second node's value to top
	stack->top->index = stack->top->next->index; // Copy second node's index to top
	stack->top->next->value = temp_val; // Restore saved value to second node
	stack->top->next->index = temp_idx; // Restore saved index to second node
}

/* sa: Swap the first two elements of stack A */
void	sa(t_stack *a)
{
	swap(a); // Perform the swap on stack A
	write(1, "sa\n", 3); // Print the operation name to stdout
}

/* sb: Swap the first two elements of stack B */
void	sb(t_stack *b)
{
	swap(b); // Perform the swap on stack B
	write(1, "sb\n", 3); // Print the operation name to stdout
}

/* ss: Swap the first two elements of both stacks simultaneously */
void	ss(t_stack *a, t_stack *b)
{
	swap(a); // Perform the swap on stack A
	swap(b); // Perform the swap on stack B
	write(1, "ss\n", 3); // Print the operation name to stdout (only once)
}
