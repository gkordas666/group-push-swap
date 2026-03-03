/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:23:11 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:23:14 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *stack)
{
	int		max;
	t_node	*tmp;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	count_bits(t_stack *stack)
{
	int	max_index;
	int	bits;

	max_index = get_max_index(stack);
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	process_bit(t_data *d, int bit)
{
	int	i;
	int	total;

	i = 0;
	total = d->a->size;
	while (i < total)
	{
		if (((d->a->top->index >> bit) & 1) == 0)
			pb(d);
		else
			ra(d);
		i++;
	}
	while (d->b->size > 0)
		pa(d);
}

void	complex_sort(t_data *d)
{
	int	max_bits;
	int	bit;

	normalize_stack(d->a->top, d->a->size);
	max_bits = count_bits(d->a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(d, bit);
		bit++;
	}
}
