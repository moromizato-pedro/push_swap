/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:39:10 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/21 03:43:40 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_2_top(int idx, int len)
{
	if (idx > len / 2)
		return (-(len - idx));
	return (idx);
}

t_stack	ft_get_min_node(t_stack *a)
{
	t_stack	min;

	min = *a;
	while (a)
	{
		if (a->data < min.data)
			min = *a;
		a = a->next;
	}
	return (min);
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

//	Returns only the amount of duplicates of data
int	ft_has_duplicate(t_stack *stack, void *data)
{
	int	count;

	count = -1;
	while (stack)
	{
		if (stack->data == data)
			count++;
		stack = stack->next;
	}
	return (count);
}

//	If there is any duplicated ref in the circularly sorted stack,
//	the min index will always be on top, unless there are duplicates
//	left on the end of the stack
int	ft_get_min_duplicate(t_stack *stack, void *ref)
{
	//	TODO: Problem is probably here, last failed attempt was
	//	./push_swap 14 3 40 21 20 8 23 33 18 39
	int	min_idx;
	int	count;

	min_idx = 0;
	count = 0;
	while (stack)
	{
		if (stack->data == ref)
		{
			count++;
			if (stack->idx - min_idx > count)
			{
				printf("Duplicate found, min_idx: %d -> %d\n", min_idx, stack->idx);
				min_idx = stack->idx;
			}
		}
		stack = stack->next;
	}
	return (min_idx);
}

//	Returns the next index after the biggest data, in order to place
//	the node from stack b that is even bigger after it.
int	ft_get_bigger(t_stack *stack)
{
	int	bigger_idx;
	void	*bigger;

	bigger = NULL;
	while (stack)
	{
		if (!bigger || bigger < stack->data)
		{
			bigger = stack->data;
			if (stack->next)
			{
				printf("	In the middle: [%d] %ld -> %d\n", stack->idx, (long)stack->data, stack->idx + 1);
				bigger_idx = stack->idx + 1;
			}
			else
			{
				printf("	In the beggining: [%d] %ld -> %d\n", stack->idx, (long)stack->data, 0);
				bigger_idx = 0;
			}
		}
		stack = stack->next;
	}
	return (bigger_idx);
}

