/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:34:57 by misasant          #+#    #+#             */
/*   Updated: 2026/02/19 14:35:14 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b || !parse_arguments(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	
	// --- ZONE DE TEST ---
	printf("Désordre avant : %f\n", get_disorder(a));
	sa(a);
	pb(a, b);
	printf("Taille A: %d, Taille B: %d\n", a->size, b->size);
	// --------------------

	free_stack(a);
	free_stack(b);
	return (0);
}
