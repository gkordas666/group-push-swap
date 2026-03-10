/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:07:04 by misasant          #+#    #+#             */
/*   Updated: 2026/03/10 15:07:06 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_in_chunk(t_stack *a, int min, int max)
{
	t_node	*current;
	int		position;

	current = a->top;
	position = 0;
	while (current)
	{
		if (current->index >= min && current->index <= max)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	find_max_pos(t_stack *b)
{
	int		pos;
	int		i;
	int		max;
	t_node	*cur;

	pos = 0;
	i = 0;
	max = b->top->index;
	cur = b->top;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

void	rotate_stack(t_data *d, int max_pos)
{
	if (max_pos <= d->b->size / 2)
		while (max_pos-- > 0)
			rb(d);
	else
		while (max_pos++ < d->b->size)
			rrb(d);
}
