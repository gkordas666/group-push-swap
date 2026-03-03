/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:40:19 by misasant          #+#    #+#             */
/*   Updated: 2026/02/17 12:41:12 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*node_to_move;

	if (!src || src->size == 0)
		return ;
	node_to_move = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node_to_move->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_move;
	else
		dest->bottom = node_to_move;
	dest->top = node_to_move;
	dest->size++;
}

void	pa(t_data *d)
{
	push(d->a, d->b);
	write(1, "pa\n", 3);
	d->stats.op[3]++;
	d->stats.total++;
}

void	pb(t_data *d)
{
	push(d->b, d->a);
	write(1, "pb\n", 3);
	d->stats.op[4]++;
	d->stats.total++;
}
