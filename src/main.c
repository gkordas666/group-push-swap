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

static int	has_bench(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	print_bench_details(t_data *d)
{
	char	*strats[] = {"adaptive", "simple", "medium", "complex"};
	char	*complexities[] = {"mixed", "O(n^2)", "O(n*sqrt(n))", "O(n*log(n))"};

	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd((int)(get_disorder(d->a) * 100), 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("Strategy: ", 2);
	ft_putstr_fd(strats[d->strat_used], 2);
	ft_putstr_fd("\nComplexity: ", 2);
	ft_putstr_fd(complexities[d->strat_used], 2);
	ft_putstr_fd("\nTotal operations: ", 2);
	ft_putnbr_fd(d->stats.total, 2);
	ft_putstr_fd("\nDetails: sa:", 2);
	ft_putnbr_fd(d->stats.op[0], 2);
	ft_putstr_fd(" pb:", 2);
	ft_putnbr_fd(d->stats.op[4], 2);
	ft_putstr_fd(" ra:", 2);
	ft_putnbr_fd(d->stats.op[5], 2);
	ft_putstr_fd("\n", 2);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc < 2)
		return (0);
	ft_memset(&d, 0, sizeof(t_data));
	d.a = init_stack();
	d.b = init_stack();
	d.bench = has_bench(argc, argv);
	if (!d.a || !d.b || !parse_arguments(argc, argv, d.a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(d.a);
		free_stack(d.b);
		return (1);
	}
	if (d.a->size > 1 && !is_sorted(d.a))
		adaptive_sort(&d);
	if (d.bench)
		print_bench_details(&d);
	free_stack(d.a);
	free_stack(d.b);
	return (0);
}
