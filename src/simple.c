/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:25:45 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:25:49 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *d)
{
	int	f;
	int	s;
	int	t;

	f = d->a->top->value;
	s = d->a->top->next->value;
	t = d->a->top->next->next->value;
	if (f > s && s < t && f < t)
		sa(d);
	else if (f > s && s > t)
	{
		sa(d);
		rra(d);
	}
	else if (f > s && s < t && f > t)
		ra(d);
	else if (f < s && s > t && f < t)
	{
		sa(d);
		ra(d);
	}
	else if (f < s && s > t && f > t)
		rra(d);
}

void	simple_sort(t_data *d)
{
	if (d->a->size == 2 && d->a->top->value > d->a->top->next->value)
		sa(d);
	else if (d->a->size == 3)
		sort_three(d);
}
