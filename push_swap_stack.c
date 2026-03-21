/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:10:45 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/20 23:06:50 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stcknew(void *data)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	stack->idx = 0;
	stack->target = -1;
	stack->cost = INT_MAX;
	return (stack);
}

void	ft_push(t_stack **stack, void *data)
{
	t_stack	*new;

	if (!stack)
		return ;
	new = ft_stcknew(data);
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		ft_reset_idxs(&new);
		*stack = new;
	}
}

void	ft_pop(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack)->next;
	if (!stack || !(*stack))
		return ;
	free(*stack);
	*stack = temp;
	ft_reset_idxs(stack);
}

int	ft_is_sorted(t_stack *stack)
{
	void	*prev;

	prev = stack->data;
	while (stack)
	{
		if (stack->data < prev)
			return (0);
		prev = stack->data;
		stack = stack->next;
	}
	return (1);
}

void	ft_reset_idxs(t_stack **stack)
{
	t_stack	*ptr;
	int	idx;

	if (!stack || !(*stack))
		return ;
	ptr = *stack;
	idx = 0;
	while (ptr)
	{
		//printf("[%d] %ld\n", ptr->idx, (long)ptr->data);
		ptr->idx = idx++;
		//printf("	[%d] %ld\n", ptr->idx, (long)ptr->data);
		ptr = ptr->next;
	}
}

int	ft_get_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

