/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:01:35 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 21:49:29 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_both(t_stack *a, t_stack *b)
{
	ft_swap_node(a, (a)->next);
	ft_swap_node(b, (b)->next);
}

//	Swap two nodes position by switching any non structural fields
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
		return ;
	ft_push(to, (*from)->data);
	ft_pop(from);
}

//	Moves all nodes upwards circularly
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

//	Moves all nodes downwards circularly
void	ft_rrotate(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*first;
	t_stack	copy_curr;
	t_stack	copy_next;

	ptr = *stack;
	first = *stack;
	copy_curr = *ptr;
	while (ptr->next)
	{
		copy_next = *ptr->next;
		ptr->next->data = copy_curr.data;
		ptr->next->target = copy_curr.target;
		ptr = ptr->next;
		copy_curr = copy_next;
	}
	first->data = copy_curr.data;
	first->target = copy_curr.target;
}
