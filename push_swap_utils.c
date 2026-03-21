/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:01:35 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/19 16:32:52 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_node(t_stack *node1, t_stack *node2)
{
	void	*temp;

	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
	temp = &node1->target;
	node1->target = node2->target;
	node2->target = *(int *)temp;
}

void	ft_push_from(t_stack **from, t_stack **to)
{
	if (!(*from))
		return (printf("Error push_from\n"), (void)0);
	ft_push(to, (*from)->data);
	ft_pop(from);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->next)
	{
		ft_swap_node(ptr, ptr->next);
		ptr = ptr->next;
	}
}

void	ft_rrotate(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*first;
	t_stack	temp;
	t_stack	copy;

	ptr = *stack;
	first = *stack;
	temp = *ptr;
	while (ptr->next)
	{
		copy = *ptr->next;
		ptr->next->data = temp.data;
		ptr->next->target = temp.target;
		ptr = ptr->next;
		temp = copy;
	}
	first->data = temp.data;
	first->target = temp.target;
}

int	ft_parse_operation(char *op, t_stack **a, t_stack **b)
{
	if (!op)
		return (write(1, "Erro\n", 5), 0);
	if (ft_strncmp(op, "sa", 2) == 0)
		return (write(1, "sa\n", 3), ft_swap_node(*a, (*a)->next), 1);
	else if (ft_strncmp(op, "sb", 2) == 0)
		return (write(1, "sb\n", 3), ft_swap_node(*b, (*b)->next), 1);
	else if (ft_strncmp(op, "ss", 2) == 0)
		return (write(1, "ss\n", 3), ft_swap_node(*a, (*a)->next), ft_swap_node(*b, (*b)->next), 1);
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
	return (write(1, "Erro\n", 5), 0);
}

