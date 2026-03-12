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

static int	process_split(char **split, t_stack *stack_a)
{
	int		j;
	long	val;
	t_node	*new;

	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			return (0);
		val = ft_atol(split[j]);
		new = node_new((int)val);
		if (!new)
			return (0);
		stack_add_back(stack_a, new);
		j++;
	}
	return (1);
}

static int	is_flag(char *arg)
{
	if (!ft_strncmp(arg, "--simple", 8) || !ft_strncmp(arg, "--medium", 8)
		|| !ft_strncmp(arg, "--complex", 9)
		|| !ft_strncmp(arg, "--adaptive", 10)
		|| !ft_strncmp(arg, "--bench", 7))
		return (1);
	return (0);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**split;

	i = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			continue ;
		if (argv[i][0] == '-' && argv[i][1] == '-')
			return (0);
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			free_split(split);
			return (0);
		}
		if (!process_split(split, stack_a))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
	}
	return (!has_duplicates(stack_a));
}
