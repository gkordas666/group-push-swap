/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:15:09 by misasant          #+#    #+#             */
/*   Updated: 2026/02/19 14:17:56 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*before_last;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->top = last;
	stack->bottom = before_last;
}

void	rra(t_data *d)
{
	rev_rotate(d->a);
	write(1, "rra\n", 4);
	d->stats.op[8]++;
	d->stats.total++;
}

void	rrb(t_data *d)
{
	rev_rotate(d->b);
	write(1, "rrb\n", 4);
	d->stats.op[9]++;
	d->stats.total++;
}

void	rrr(t_data *d)
{
	rev_rotate(d->a);
	rev_rotate(d->b);
	write(1, "rrr\n", 4);
	d->stats.op[10]++;
	d->stats.total++;
}
