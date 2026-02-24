/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:49:45 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/24 20:05:21 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **stack, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	node->next = *stack;
	*stack = node;
}

void	ft_pop(t_list **stack)
{
	t_list	*prev;

	if (!stack)
		return ;
	prev = *stack;
	*stack = (*stack)->next;
	prev->content = NULL;
	prev->next = NULL;
	if (prev)
		free(prev);
	prev = NULL;
}

void	ft_push_from(t_list **from, t_list **to)
{
	ft_push(to, (*from)->content);
	ft_pop(from);
}

void	_get_stacks(t_list *a, t_list *b)
{
	printf("A:\n");
	ft_get_stack(a);
	printf("B:\n\n");
	ft_get_stack(b);
}
