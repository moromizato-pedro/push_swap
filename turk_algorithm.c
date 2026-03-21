/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:40:18 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/21 03:35:55 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Gets the index of the number which the reference should be placed before.
int	ft_get_min_bigger(t_stack *stack, void *ref)
{
	void	*min_bigger;
	int	min_bigger_idx;
	t_stack	*start;
	
	min_bigger = NULL;
	min_bigger_idx = 0;
	start = stack;
	while (stack)
	{
		if (stack->data > ref && (!min_bigger || stack->data < min_bigger))
		{
			min_bigger = stack->data;
			min_bigger_idx = stack->idx;
		}
		stack = stack->next;
	}
	if (ft_has_duplicate(start, min_bigger))
	{
		printf("			Duplicate found\n");
		printf("			min_bigger: %d -> ", min_bigger_idx);
		min_bigger_idx = ft_get_min_duplicate(start, min_bigger);
		printf("%d\n", min_bigger_idx);
	}
	else if (!min_bigger)
	{
		printf("			Bigger found\n");
		printf("			min_bigger: %d -> ", min_bigger_idx);
		min_bigger_idx = ft_get_bigger(start);
		printf("%d\n", min_bigger_idx);
	}
	return (min_bigger_idx);
}

t_stack	ft_find_cheapest_node(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_stack	cheapest;
	int	min_cost;
	int	cost;

	ptr = *b;
	min_cost = -1;
	/*printf("A:\n");
	_ft_get_stack(*a);
	printf("B:\n");
	_ft_get_stack(*b);
	printf("---\n");*/
	while (ptr)
	{
		ptr->target = ft_get_min_bigger(*a, ptr->data);
		printf("B(%d) -> A(%d) | CostA: %d CostB: %d\n", ptr->idx, ptr->target, ft_cost_2_top(ptr->target, ft_get_len(*a)), ft_cost_2_top(ptr->idx, ft_get_len(*b)));
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

int	ft_sort_cheapest(t_stack **a, t_stack **b, t_stack cheapest)
{
	int	cost_a;
	int	cost_b;
	int	ops;

	cost_a = ft_cost_2_top(cheapest.target, ft_get_len(*a));
	cost_b = ft_cost_2_top(cheapest.idx, ft_get_len(*b));
	ops = 0;
	printf("Cheapest: [%d] -> [%d]\n", cheapest.idx, cheapest.target);
	ops += ft_move_2_top(a, b, cost_a, cost_b);
	printf("A:\n");
	_ft_get_stack(*a);
	printf("B:\n");
	_ft_get_stack(*b);
	ops += ft_parse_operation("pa", a, b);
	printf("A:\n");
	_ft_get_stack(*a);
	printf("B:\n");
	_ft_get_stack(*b);
	//ops += ft_reorder_a(a, cost_a);
	/*printf("A:\n");
	_ft_get_stack(*a);
	printf("B:\n");
	_ft_get_stack(*b);
	*/return (ops);
}

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
		printf("		cost_a: %d | cost_b: %d\n", cost_a, cost_b);
		ft_update_costs(&cost_a, &cost_b);
	}
	return (ops);
}

int	ft_reorder_a(t_stack **a, int cost_a)
{
	t_stack	min_node;
	int	ops;

	min_node = ft_get_min_node(*a);
	ops = 0;
	printf("min_idx: %d -> ", min_node.idx);
	if (ft_has_duplicate(*a, min_node.data))
		min_node.idx = ft_get_min_duplicate(*a, min_node.data);
	printf("%d\n", min_node.idx);
	cost_a = ft_cost_2_top(min_node.idx, ft_get_len(*a));
/*	
	//	Reordering for always ordered stack
	int	ops;

	ops = 0;
	printf("		cost_a: %d -> ", cost_a);
	if (cost_a < 0)
		cost_a--;
	else if (cost_a == 0)
		if ((*a)->data > (*a)->next->data)
			cost_a--;
	cost_a = -cost_a;
	printf("%d\n", cost_a);
*/
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

int	ft_turk_algorithm(t_stack **a, t_stack **b)
{
	t_stack cheapest;
	int	ops;

	ops = 0;
	while (*b)
	{
		printf("A:\n");
		_ft_get_stack(*a);
		printf("B:\n");
		_ft_get_stack(*b);
		cheapest = ft_find_cheapest_node(a, b);
		ops += ft_sort_cheapest(a, b, cheapest);
	}
	ops += ft_reorder_a(a, 0);
	return (ops);
}

