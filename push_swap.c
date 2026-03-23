/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:01:12 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 03:00:14 by pedrohe3         ###   ########.fr       */
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
	//printf("min_bigger(%ld): %d\n", (long)(*b)->data, ft_get_min_bigger(*a, (*b)->data));
	ops += ft_turk_algorithm(a, b);
	//_ft_get_stack(*a);
	/*if (ft_is_sorted(*a))
		printf("Sorted!\n");
	else
		printf("Not Sorted =(\n");
	*/return (ops);
}

//	While a 4th node is found remove top node
int	ft_isolate_3(t_stack **a, t_stack **b)
{
	int	ops;

	ops = 0;
	if (ft_get_len(*a) > 3)
		while ((*a)->next->next->next)
			ops += ft_parse_operation("pb", a, b);
	return (ops);
}

//	Bubble sort
int	ft_order_3(t_stack **a)
{
	int	i;
	int	j;
	int	ops;

	i = ft_get_len(*a) - 1;
	ops = 0;
	while (i-- > 0)
	{
		j = ft_get_len(*a) - 1;
		while (j-- > 0)
		{
			if ((long)(*a)->data > (long)(*a)->next->data && !ft_is_sorted(*a))
				ops += ft_parse_operation("sa", a, NULL);
			if (!ft_is_sorted(*a))
				ops += ft_parse_operation("ra", a, NULL);
		}
		if (!ft_is_sorted(*a))
			ops += ft_parse_operation("ra", a, NULL);
	}
	return (ops);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*params;
	t_stack	*ptr;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		/*if (ac == 2)
		{
			//printf("Create stack with random numbers\n");
			a = _ft_fill_stack(av[1]);
			//printf("A:\n");
			//_ft_get_stack(a);
		}
		else */if (ac > 1)
		{
			//printf("Create a specific stack\n");
			a = ft_create_stack(ac - 1, av);
			//printf("A:\n");
			if (!a)
				return (write(2, "Error\n", 6), 0);
			//_ft_get_stack(a);
		//}
			params = ft_get_params(a);
			ptr = params;
			while (ptr)
			{
				if (ft_has_duplicate(params, ptr->data))
					return (write(2, "Error\n", 6), 0);
				ptr = ptr->next;
			}
			//printf("Operations: %d\n", ft_push_swap(&a, &b));
			ft_push_swap(&a, &b);
			//printf("Params: ");
		}
	}
	return (0);
}
