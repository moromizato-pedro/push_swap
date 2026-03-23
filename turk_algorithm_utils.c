/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:39:10 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 02:57:49 by pedrohe3         ###   ########.fr       */
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
		if ((long)a->data < (long)min.data)
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
	//printf("			(updated) cost_a: %d | cost_b: %d\n", *cost_a, *cost_b);
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
	if (count < 0)
		return (0);
	return (count);
}

//	If there are any duplicates they can be separated at the last and first node,
//	otherwise they will be sequential. When sequential count will be the same as
//	the differences between the current idx and the mini.
int	ft_get_min_duplicate(t_stack *stack, void *ref)
{
	int	min_idx;
	int	count;

	min_idx = -1;
	count = 0;
	while (stack)
	{
		if (stack->data == ref)
		{
			if (min_idx < 0)
				min_idx = stack->idx;
			count++;
			if (stack->idx - min_idx > count)
			{
				//printf("Duplicate found, min_idx: %d -> %d\n", min_idx, stack->idx);
				min_idx = stack->idx;
			}
		}
		stack = stack->next;
	}
	return (min_idx);
}

//	If there are any duplicates they can be separated at the last and first node,
//	otherwise they will be sequential. When sequential count will be the same as
//	the differences between the current idx and the mini.
int	ft_get_max_duplicate(t_stack *stack, void *ref)
{
	int	max_idx;
	int	count;

	max_idx = -1;
	count = -1;
	while (stack)
	{
		if (stack->data == ref)
		{
			count++;
			//printf("%d - %d == %d ? %d\n", stack->idx, max_idx, count, stack->idx - max_idx == count);
			if (max_idx < 0)
				max_idx = stack->idx;
			else if (stack->idx - max_idx == 1)
			{
				//printf("Duplicate %d found, max_idx: %d -> %d\n", count, max_idx, stack->idx);
				max_idx = stack->idx;
			}
		}
		stack = stack->next;
	}
	return (max_idx);
}

//	Returns the next index after the biggest data, in order to place
//	the node from stack b that is even bigger after it.
int	ft_get_bigger(t_stack *stack)
{
	int	bigger_idx;
	//void	*bigger;
	t_stack	bigger;
	t_stack	*ptr;

	bigger = *stack;
	ptr = stack;
	while (ptr)
	{
		if ((long)ptr->data > (long)bigger.data)
			bigger = *ptr;
		ptr = ptr->next;
	}
	bigger_idx = ft_get_max_duplicate(stack, bigger.data);
	//printf("bigger: %d -> ", bigger_idx);
	if (bigger_idx != (ft_get_len(stack) - 1))
		bigger_idx++;
	else
		bigger_idx = 0;
	//printf("%d\n", bigger_idx);
	return (bigger_idx);
}

