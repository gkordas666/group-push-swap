/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:41:38 by misasant          #+#    #+#             */
/*   Updated: 2026/02/17 13:19:37 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp_val;
	int	temp_idx;

	if (!stack || stack->size < 2)
		return ;
	temp_val = stack->top->value;
	temp_idx = stack->top->index;
	stack->top->value = stack->top->next->value;
	stack->top->index = stack->top->next->index;
	stack->top->next->value = temp_val;
	stack->top->next->index = temp_idx;
}

void	sa(t_data *d)
{
	swap(d->a);
	write(1, "sa\n", 3);
	d->stats.op[0]++;
	d->stats.total++;
}

void	sb(t_data *d)
{
	swap(d->b);
	write(1, "sb\n", 3);
	d->stats.op[1]++;
	d->stats.total++;
}

void	ss(t_data *d)
{
	swap(d->a);
	swap(d->b);
	write(1, "ss\n", 3);
	d->stats.op[2]++;
	d->stats.total++;
}
