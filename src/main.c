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

static void	set_strategy(t_data *d, int argc, char **argv)
{
	if (has_flag(argc, argv, "--simple"))
		d->strat_forced = STRAT_SIMPLE;
	else if (has_flag(argc, argv, "--medium"))
		d->strat_forced = STRAT_MEDIUM;
	else if (has_flag(argc, argv, "--complex"))
		d->strat_forced = STRAT_COMPLEX;
	else
		d->strat_forced = STRAT_ADAPTIVE;
}

static void	run_sort(t_data *d)
{
	if (d->strat_forced == STRAT_SIMPLE)
	{
		d->strat_used = STRAT_SIMPLE;
		simple_sort(d);
	}
	else if (d->strat_forced == STRAT_MEDIUM)
	{
		d->strat_used = STRAT_MEDIUM;
		medium_sort(d);
	}
	else if (d->strat_forced == STRAT_COMPLEX)
	{
		d->strat_used = STRAT_COMPLEX;
		complex_sort(d);
	}
	else
	{
		d->strat_used = STRAT_ADAPTIVE;
		adaptive_sort(d);
	}
}

int	main(int argc, char **argv)
{
	t_data	d;
	double	initial_disorder;

	if (argc < 2)
		return (0);
	ft_memset(&d, 0, sizeof(t_data));
	d.a = init_stack();
	d.b = init_stack();
	d.bench = has_flag(argc, argv, "--bench");
	set_strategy(&d, argc, argv);
	if (!d.a || !d.b || !parse_arguments(argc, argv, d.a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(d.a);
		free_stack(d.b);
		return (1);
	}
	initial_disorder = get_disorder(d.a);
	if (d.a->size > 1 && !is_sorted(d.a))
		run_sort(&d);
	if (d.bench)
		print_bench_details(&d, initial_disorder);
	free_stack(d.a);
	free_stack(d.b);
	return (0);
}
