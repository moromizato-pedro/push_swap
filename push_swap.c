/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:01:12 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 21:50:51 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Try to creates 'a' stack, looks for duplicates,if all values are unique, 
//	do the push_swap.
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*ptr;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		a = ft_create_stack(ac - 1, av);
		if (!a)
			return (write(2, "Error\n", 6), 0);
		ptr = a;
		while (ptr)
		{
			if (ft_has_duplicate(a, ptr->data))
				return (write(2, "Error\n", 6), 0);
			ptr = ptr->next;
		}
		ft_push_swap(&a, &b);
	}
	return (0);
}

int	ft_push_swap(t_stack **a, t_stack **b)
{
	int	ops;

	ops = 0;
	if (!a || !b)
		return (ops);
	ops += ft_isolate_3(a, b);
	ops += ft_order_3(a);
	ops += ft_turk_algorithm(a, b);
	return (ops);
}

//	While a 4th node is found push top node to 'b'.
int	ft_isolate_3(t_stack **a, t_stack **b)
{
	int	ops;

	ops = 0;
	if (ft_get_len(*a) > 3)
		while ((*a)->next->next->next)
			ops += ft_parse_operation("pb", a, b);
	return (ops);
}

//	Bubble sort the 'a' stack and return the number of operations used. 
//	Stops if gets sorted before the bubble sort finishes to save moves.
int	ft_order_3(t_stack **a)
{
	int	len;
	int	len_cpy;
	int	operations;

	len = ft_get_len(*a);
	operations = 0;
	if (len < 2)
		return (operations);
	while (len-- > 0)
	{
		len_cpy = ft_get_len(*a);
		while (len_cpy-- > 0)
		{
			if ((long)(*a)->data > (long)(*a)->next->data && !ft_is_sorted(*a))
				operations += ft_parse_operation("sa", a, NULL);
			if (!ft_is_sorted(*a))
				operations += ft_parse_operation("ra", a, NULL);
		}
		if (!ft_is_sorted(*a))
			operations += ft_parse_operation("ra", a, NULL);
	}
	return (operations);
}

int	ft_parse_operation(char *op, t_stack **a, t_stack **b)
{
	if (!op)
		return (write(2, "Erro\n", 5), 0);
	if (ft_strncmp(op, "sa", 2) == 0)
		return (write(1, "sa\n", 3), ft_swap_node(*a, (*a)->next), 1);
	else if (ft_strncmp(op, "sb", 2) == 0)
		return (write(1, "sb\n", 3), ft_swap_node(*b, (*b)->next), 1);
	else if (ft_strncmp(op, "ss", 2) == 0)
		return (write(1, "ss\n", 3), ft_swap_both(*a, *b), 1);
	else if (ft_strncmp(op, "pa", 2) == 0)
		return (write(1, "pa\n", 3), ft_push_from(b, a), 1);
	else if (ft_strncmp(op, "pb", 2) == 0)
		return (write(1, "pb\n", 3), ft_push_from(a, b), 1);
	else if (ft_strncmp(op, "rra", 3) == 0)
		return (write(1, "rra\n", 4), ft_rrotate(a), 1);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		return (write(1, "rrb\n", 4), ft_rrotate(b), 1);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		return (write(1, "rrr\n", 4), ft_rrotate(a), ft_rrotate(b), 1);
	else if (ft_strncmp(op, "ra", 2) == 0)
		return (write(1, "ra\n", 3), ft_rotate(a), 1);
	else if (ft_strncmp(op, "rb", 2) == 0)
		return (write(1, "rb\n", 3), ft_rotate(b), 1);
	else if (ft_strncmp(op, "rr", 2) == 0)
		return (write(1, "rr\n", 3), ft_rotate(a), ft_rotate(b), 1);
	return (write(2, "Erro\n", 5), 0);
}
