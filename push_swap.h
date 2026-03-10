/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:03:49 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 15:03:54 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

# define STRAT_ADAPTIVE 0
# define STRAT_SIMPLE   1
# define STRAT_MEDIUM   2
# define STRAT_COMPLEX  3

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_stats
{
	int	op[11];
	int	total;
}	t_stats;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_stats	stats;
	int		bench;
	int		strat_used;
	int		strat_forced;
}	t_data;

/* --- Benchmarking & Flags (bench.c) --- */
void	print_bench_details(t_data *d, double disorder);
int		has_flag(int argc, char **argv, const char *flag);

/* --- Stack Management (stack_init.c) --- */
t_stack	*init_stack(void);
t_node	*node_new(int value);
void	stack_add_back(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);

/* --- Parsing & Utils (parsing.c / swap_util.c) --- */
int		parse_arguments(int argc, char **argv, t_stack *stack_a);
void	free_split(char **split);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
long	ft_atol(const char *str);
int		is_sorted(t_stack *stack);
double	get_disorder(t_stack *stack);

/* --- Algorithms --- */
void	adaptive_sort(t_data *d);
void	simple_sort(t_data *d);
void	medium_sort(t_data *d);
void	complex_sort(t_data *d);
void	normalize_stack(t_node *top, int size);

/* --- Operations (doivent toutes prendre t_data *d) --- */
void	sa(t_data *d);
void	sb(t_data *d);
void	ss(t_data *d);
void	pa(t_data *d);
void	pb(t_data *d);
void	ra(t_data *d);
void	rb(t_data *d);
void	rr(t_data *d);
void	rra(t_data *d);
void	rrb(t_data *d);
void	rrr(t_data *d);

#endif
