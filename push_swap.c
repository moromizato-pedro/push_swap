/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:01:12 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/21 01:26:28 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(t_stack **a, t_stack **b)
{
	int	ops;

	ops = 0;
	if (!a || !b)
		return (ops);
	ops += ft_isolate_3(a, b);
	ops += ft_order_3(a);
	printf("min_bigger(%ld): %d\n", (long)(*b)->data, ft_get_min_bigger(*a, (*b)->data));
	ops += ft_turk_algorithm(a, b);
	_ft_get_stack(*a);
	if (ft_is_sorted(*a))
		printf("Sorted!\n");
	else
		printf("Not Sorted =(\n");
	return (ops);
}

int	ft_isolate_3(t_stack **a, t_stack **b)
{
	int	ops;

	ops = 0;
	//	While a 4th node is found remove top node
	while ((*a)->next->next->next)
		ops += ft_parse_operation("pb", a, b);
	return (ops);
}

int	ft_order_3(t_stack **a)
{
	int	i;
	int	j;
	int	ops;

	i = 2;
	ops = 0;
	while (i-- > 0)
	{
		j = 2;
		//	Brings the biggest data to the last
		while (j-- > 0)
		{
			if ((*a)->data > (*a)->next->data && !ft_is_sorted(*a))
			//{
				ops += ft_parse_operation("sa", a, NULL);
			//	_ft_get_stack(*a);
			//}
			if (!ft_is_sorted(*a))
			//{
				ops += ft_parse_operation("ra", a, NULL);
			//	_ft_get_stack(*a);
			//}
		}
		//	Go back to start
		if (!ft_is_sorted(*a))
		//{
			ops += ft_parse_operation("ra", a, NULL);
		//	_ft_get_stack(*a);
		//}
	}
	return (ops);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		if (ac == 2)
		{
			printf("Create stack with random numbers\n");
			a = _ft_fill_stack(av[1]);
			printf("A:\n");
			_ft_get_stack(a);
		}
		else if (ac > 2)
		{
			printf("Create a specific stack\n");
			a = ft_create_stack(av);
			printf("A:\n");
			_ft_get_stack(a);
		}
		printf("Operations: %d\n", ft_push_swap(&a, &b));
	}
	write(1, "\n", 1);
	return (0);
}
