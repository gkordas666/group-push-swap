/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:55:19 by gkordas           #+#    #+#             */
/*   Updated: 2026/03/12 09:55:28 by gkordas          ###   ########.fr       */
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
		simple_sort(d);
	else if (size <= 5)
		medium_sort(d);
	else
		complex_sort(d);
}
