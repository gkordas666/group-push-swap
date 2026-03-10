/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:45 by misasant          #+#    #+#             */
/*   Updated: 2026/03/09 14:20:53 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_flag(int argc, char **argv, const char *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], flag, ft_strlen(flag) + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_bench_details(t_data *d, double disorder)
{
	char	*names[4];
	char	*classes[4];
	int		*o;

	names[0] = "Adaptive";
	names[1] = "Simple";
	names[2] = "Medium";
	names[3] = "Complex";
	classes[0] = "mixed";
	classes[1] = "O(n^2)";
	classes[2] = "O(n*sqrt(n))";
	classes[3] = "O(n*log(n))";
	o = d->stats.op;
	dprintf(2, "[bench] disorder:  %.2f%%\n", disorder * 100);
	dprintf(2, "[bench] strategy:  %s\n", names[d->strat_used]);
	dprintf(2, "[bench] Complexity: %s\n", classes[d->strat_used]);
	dprintf(2, "[bench] total_ops:  %d\n", d->stats.total);
	dprintf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		o[0], o[1], o[2], o[3], o[4]);
	dprintf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		o[5], o[6], o[7], o[8], o[9], o[10]);
}
