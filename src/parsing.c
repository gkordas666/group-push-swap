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

/* Converts a string to a long integer (to detect int overflow) */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/* Returns 1 if there are duplicate values in the stack */
int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	// 1. Si la string est vide après le split (ne devrait pas arriver mais sécurité)
	if (!str[i])
		return (0);
	// 2. Gestion du signe
	if (str[i] == '-')
	{
		i++;
		// ERREUR CRUCIALE : Si on a un '-' il DOIT y avoir un chiffre après
		// C'est ici que le "--2" sera détecté car str[1] est '-' et non un chiffre
		if (!str[i] || !ft_isdigit(str[i]))
			return (0);
	}
	// 3. Refus des zéros inutiles (ex: "01")
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	// 4. On vérifie que tout le reste sont des chiffres
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	// 5. Overflow et -0
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (num == 0 && str[0] == '-')
		return (0);
	return (1);
}

static int	process_split(char **split, t_stack *stack_a)
{
	int		i;
	t_node	*new;

	i = 0;
	if (!split || !split[0])
		return (0);
	while (split[i])
	{
		if (!is_valid_number(split[i]))
			return (0);
		new = node_new((int)ft_atol(split[i]));
		if (!new)
			return (0);
		stack_add_back(stack_a, new);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0
		|| ft_strncmp(argv[i], "--medium", 9) == 0
		|| ft_strncmp(argv[i], "--complex", 10) == 0
		|| ft_strncmp(argv[i], "--bench", 8) == 0
		|| ft_strncmp(argv[i], "--adaptive", 11) == 0)
		{
			i++;
			continue ;
		}
		// Erreur si l'argument est vide "" ou juste des espaces
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			if (split)
				free_split(split);
			return (0);
		}
		if (!process_split(split, stack_a))
			return (free_split(split), 0);
		free_split(split);
		i++;
	}
	return (!has_duplicates(stack_a));
}
