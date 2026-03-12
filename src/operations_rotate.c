/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:56:34 by misasant          #+#    #+#             */
/*   Updated: 2026/02/17 13:56:36 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	last = stack->bottom;
	stack->top = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->bottom = first;
}

void	ra(t_data *d)
{
	rotate(d->a);
	write(1, "ra\n", 3);
	d->stats.op[5]++;
	d->stats.total++;
}

void	rb(t_data *d)
{
	rotate(d->b);
	write(1, "rb\n", 3);
	d->stats.op[6]++;
	d->stats.total++;
}

void	rr(t_data *d)
{
	rotate(d->a);
	rotate(d->b);
	write(1, "rr\n", 3);
	d->stats.op[7]++;
	d->stats.total++;
}
