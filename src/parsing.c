/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:20:40 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 16:26:15 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h" // Include all structures and prototypes

/* Converts a string to a long integer (to detect int overflow) */
long	ft_atol(const char *str)
{
	long	result; // Stores the converted number
	int		sign; // Stores the sign (+1 or -1)

	result = 0; // Initialize result to zero
	sign = 1; // Default sign is positive
	while (*str == ' ' || (*str >= 9 && *str <= 13)) // Skip whitespace characters
		str++; // Move to next character
	if (*str == '-' || *str == '+') // If there is a sign character
	{
		if (*str == '-') // If the sign is negative
			sign = -1; // Set sign to -1
		str++; // Move past the sign character
	}
	while (*str >= '0' && *str <= '9') // While current char is a digit
	{
		result = result * 10 + (*str - '0'); // Shift result left and add digit
		str++; // Move to next character
	}
	return (result * sign); // Apply sign and return the final value
}

/* Returns 1 if the string is a valid integer within INT_MIN/INT_MAX, 0 otherwise */
int	is_valid_number(char *str)
{
	int		i; // Index to traverse the string
	long	num; // Stores the converted value as long for overflow check

	i = 0; // Start at the beginning of the string
	if (str[i] == '-' || str[i] == '+') // If there is a sign character
		i++; // Skip it
	if (!str[i]) // If string is empty after sign
		return (0); // Not a valid number
	while (str[i]) // Loop through remaining characters
	{
		if (str[i] < '0' || str[i] > '9') // If character is not a digit
			return (0); // Not a valid number
		i++; // Move to next character
	}
	num = ft_atol(str); // Convert string to long to check for overflow
	if (num < INT_MIN || num > INT_MAX) // If value is outside int range
		return (0); // Overflow detected, not valid
	return (1); // All checks passed, valid number
}

/* Returns 1 if there are duplicate values in the stack, 0 otherwise */
int	has_duplicates(t_stack *stack)
{
	t_node	*current; // Outer loop pointer
	t_node	*checker; // Inner loop pointer to compare against current

	current = stack->top; // Start outer loop from the top
	while (current) // Loop through all nodes
	{
		checker = current->next; // Start inner loop from the node after current
		while (checker) // Loop through remaining nodes
		{
			if (current->value == checker->value) // If two values are equal
				return (1); // Duplicate found
			checker = checker->next; // Move inner pointer forward
		}
		current = current->next; // Move outer pointer forward
	}
	return (0); // No duplicates found
}

/* Processes a single token, validates it and adds it to the stack */
static int	process_token(char *token, t_stack *stack_a)
{
	int	value; // Stores the converted integer value

	if (!is_valid_number(token)) // If the token is not a valid integer
		return (0); // Return failure
	value = (int)ft_atol(token); // Convert token to int safely via long
	stack_add_back(stack_a, node_new(value)); // Create node and add to stack
	return (1); // Return success
}

/* Parses all arguments and fills stack A, returns 0 on error */
int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i; // Index to traverse argv
	int		j; // Index to traverse split result
	char	**split; // Array of strings from ft_split

	i = 1; // Start from argv[1] (skip program name)
	while (i < argc) // Loop through all arguments
	{
		split = ft_split(argv[i], ' '); // Split argument by spaces
		if (!split) // If ft_split failed
			return (0); // Return failure
		j = 0; // Start from first token
		while (split[j]) // Loop through all tokens
		{
			if (!process_token(split[j], stack_a)) // If token is invalid
			{
				free_split(split); // Free the split array
				return (0); // Return failure
			}
			j++; // Move to next token
		}
		free_split(split); // Free split after processing all tokens
		i++; // Move to next argument
	}
	if (has_duplicates(stack_a)) // Check for duplicate values in the stack
		return (0); // Duplicates found, return failure
	return (1); // All arguments valid, return success
}
