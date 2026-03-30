/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:17:28 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/30 22:58:23 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	void	*prev;

	prev = stack->data;
	while (stack)
	{
		if ((long long)stack->data < (long long)prev)
			return (0);
		prev = stack->data;
		stack = stack->next;
	}
	return (1);
}

void	ft_reset_idxs(t_stack **stack)
{
	t_stack	*ptr;
	int		idx;

	if (!stack || !(*stack))
		return ;
	ptr = *stack;
	idx = 0;
	while (ptr)
	{
		ptr->idx = idx++;
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
