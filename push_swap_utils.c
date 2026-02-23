/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:49:45 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/23 19:22:30 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **stack, t_list *node)
{
	node->next = *stack;
	*stack = node;
}

void	ft_pop(t_list *stack)
{
	t_list	*prev;

	if (!stack)
		return ;
	prev = stack;
	stack = stack->next;
	prev->content = NULL;
	free(prev);
}
