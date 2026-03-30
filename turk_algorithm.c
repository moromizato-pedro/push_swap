/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:40:18 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/30 22:45:28 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_turk_algorithm(t_stack **a, t_stack **b)
{
	t_stack	cheapest;
	int		ops;
	int		cost_a;
	int		cost_b;

	ops = 0;
	while (*b)
	{
		cheapest = ft_find_cheapest_node(a, b);
		cost_a = ft_cost_2_top(cheapest.target, ft_get_len(*a));
		cost_b = ft_cost_2_top(cheapest.idx, ft_get_len(*b));
		ops += ft_move_2_top(a, b, cost_a, cost_b);
		ops += ft_parse_operation("pa", a, b);
	}
	ops += ft_reorder_a(a, 0);
	return (ops);
}

//	Returns a copy of the node with lowest cost to place both node and target
//	at top.
t_stack	ft_find_cheapest_node(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_stack	cheapest;
	int		min_cost;
	int		cost;

	ptr = *b;
	min_cost = -1;
	while (ptr)
	{
		ptr->target = ft_get_min_bigger(*a, ptr->data);
		cost = ft_abs(ft_cost_2_top(ptr->target, ft_get_len(*a)));
		cost += ft_abs(ft_cost_2_top(ptr->idx, ft_get_len(*b)));
		if (min_cost < 0 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = *ptr;
		}
		ptr = ptr->next;
	}
	return (cheapest);
}

//	Gets the index of the node which the reference should be placed before.
//	If ref is bigger than all stack, put it at the beggining.
int	ft_get_min_bigger(t_stack *stack, void *ref)
{
	t_stack	*min_bigger;
	t_stack	*min;
	t_stack	*start;

	min = NULL;
	min_bigger = NULL;
	start = stack;
	while (stack)
	{
		if ((long)ref < (long)stack->data && (!min_bigger
				|| (long)min_bigger->data > (long)stack->data))
			min_bigger = stack;
		else if (!min || (long)min->data > (long)stack->data)
			min = stack;
		stack = stack->next;
	}
	if (!min_bigger)
		return (ft_get_idx(start, min->data));
	return (min_bigger->idx);
}

//	If the cost is negative moves the stack downwards circularly, otherwise
//	moves it upwards, and if has no cost, don't move it.
int	ft_move_2_top(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	ops;

	ops = 0;
	while (cost_a || cost_b)
	{
		if (cost_a < 0 && cost_b < 0)
			ops += ft_parse_operation("rrr", a, b);
		else if (cost_a > 0 && cost_b > 0)
			ops += ft_parse_operation("rr", a, b);
		else
		{
			if (cost_a < 0)
				ops += ft_parse_operation("rra", a, NULL);
			if (cost_b < 0)
				ops += ft_parse_operation("rrb", NULL, b);
			if (cost_a > 0)
				ops += ft_parse_operation("ra", a, NULL);
			if (cost_b > 0)
				ops += ft_parse_operation("rb", NULL, b);
		}
		ft_update_costs(&cost_a, &cost_b);
	}
	return (ops);
}

int	ft_reorder_a(t_stack **a, int cost_a)
{
	int	min_data_idx;
	int	ops;

	min_data_idx = ft_get_min_data_idx(*a);
	ops = 0;
	cost_a = ft_cost_2_top(min_data_idx, ft_get_len(*a));
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ops += ft_parse_operation("ra", a, NULL);
			cost_a--;
		}
		else if (cost_a < 0)
		{
			ops += ft_parse_operation("rra", a, NULL);
			cost_a++;
		}
	}
	return (ops);
}
