/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:25 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 16:46:30 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i; // Index to traverse the array

	i = 0; // Start at the first string
	while (split[i]) // While current string is not NULL
	{
		free(split[i]); // Free the current string
		i++; // Move to next string
	}
	free(split); // Free the array of pointers itself
}

void	free_stack(t_stack *stack)
{
	t_node	*current; // Pointer to traverse the list
	t_node	*next; // Temporary pointer to save next before freeing current

	if (!stack) // If stack is NULL
		return ; // Nothing to free
	current = stack->top; // Start from the top of the stack
	while (current) // While there are nodes to free
	{
		next = current->next; // Save the next node before freeing current
		free(current); // Free the current node
		current = next; // Move to the saved next node
	}
	free(stack); // Free the stack structure itself
}
