/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:39:10 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 21:03:22 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	If at the upper half, idx = number of upward rotations to get to top
//	If at the lower half, idx = number of downward rotations to get to top
int	ft_cost_2_top(int idx, int len)
{
	if (idx > len / 2)
		return (-(len - idx));
	return (idx);
}

//	As for the application of this project the datase will never 
//	be big enough to reach a cost of INT_MIN/INT_MAX there is no need
//	to worry about those edge cases.
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_get_idx(t_stack *stack, void *ref)
{
	int	idx;

	if (!stack || !ref)
		return (-1);
	idx = -1;
	while (stack)
	{
		if (stack->data == ref)
			return (stack->idx);
		stack = stack->next;
	}
	return (idx);
}

void	ft_update_costs(int *cost_a, int *cost_b)
{
	if (!cost_a || !cost_b)
		return ;
	if (*cost_a < 0)
		*cost_a += 1;
	if (*cost_a > 0)
		*cost_a -= 1;
	if (*cost_b < 0)
		*cost_b += 1;
	if (*cost_b > 0)
		*cost_b -= 1;
}

int	ft_get_min_data_idx(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if ((long)a->data < (long)min->data)
			min = a;
		a = a->next;
	}
	return (min->idx);
}
