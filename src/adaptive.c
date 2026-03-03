/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:22:49 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:22:56 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_data *d)
{
	int	size;

	if (!d->a || !d->a->top)
		return ;
	size = d->a->size;
	if (size <= 3)
	{
		d->strat_used = STRAT_SIMPLE;
		simple_sort(d);
	}
	else if (size <= 5)
	{
		d->strat_used = STRAT_MEDIUM;
		medium_sort(d);
	}
	else
	{
		d->strat_used = STRAT_COMPLEX;
		complex_sort(d);
	}
}
