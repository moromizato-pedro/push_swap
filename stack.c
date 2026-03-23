/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:10:45 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 21:24:01 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stcknew(void *data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	stack->idx = 0;
	stack->target = -1;
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
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	ft_reset_idxs(stack);
}
