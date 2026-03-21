/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:39:10 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/21 00:41:43 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_2_top(int idx, int len)
{
	if (idx > len / 2)
		return (-(len - idx));
	return (idx);
}

int	ft_get_min(t_stack *a)
{
	t_stack	min;

	min = *a;
	while (a)
	{
		if (a->data < min.data)
			min = *a;
		a = a->next;
	}
	return (min.idx);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_update_costs(int *cost_a, int *cost_b)
{
	if (*cost_a < 0)
		*cost_a += 1;
	if (*cost_a > 0)
		*cost_a -= 1;
	if (*cost_b < 0)
		*cost_b += 1;
	if (*cost_b > 0)
		*cost_b -= 1;
	printf("			(updated) cost_a: %d | cost_b: %d\n", *cost_a, *cost_b);
}

