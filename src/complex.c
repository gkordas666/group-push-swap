/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:06:23 by misasant          #+#    #+#             */
/*   Updated: 2026/03/10 15:06:25 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *a)
{
	int		max;
	t_node	*tmp;

	if (!a || !a->top)
		return (0);
	tmp = a->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static int	count_bits(t_stack *a)
{
	int	max_index;
	int	bits;

	max_index = get_max_index(a);
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_bit(t_data *d, int bit)
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
