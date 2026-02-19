/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:56:29 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 16:57:23 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

/*
** Calculates the disorder ratio of the stack (between 0.0 and 1.0).
** 0.0 = Perfectly sorted (no inversions).
** 1.0 = Completely reversed (maximum inversions).
** Student B uses this value to choose the best sorting strategy.
*/
double	get_disorder(t_stack *stack)
{
	t_node	*i; // Outer loop pointer
	t_node	*j; // Inner loop pointer
	int		mistakes; // Counts the number of inversions found
	int		total_pairs; // Total number of comparable pairs

	if (!stack || stack->size < 2) // If stack is NULL or has less than 2 elements
		return (0.0); // No disorder possible, return 0
	mistakes = 0; // Initialize inversion counter to zero
	total_pairs = stack->size * (stack->size - 1) / 2; // Formula: n*(n-1)/2
	i = stack->top; // Start outer loop from the top
	while (i) // Loop through all nodes
	{
		j = i->next; // Start inner loop from the node after i
		while (j) // Loop through all nodes after i
		{
			if (i->value > j->value) // If a larger value appears before a smaller one
				mistakes++; // Count it as an inversion
			j = j->next; // Move inner pointer forward
		}
		i = i->next; // Move outer pointer forward
	}
	return ((double)mistakes / (double)total_pairs); // Return ratio as a double
}
