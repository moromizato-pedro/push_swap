/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:49:45 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/26 03:25:49 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **stack, void *content)
{
	t_list	*node;

	if (!(*stack) || !(long)content)
		return ;
	node = ft_lstnew(content);
	node->next = *stack;
	*stack = node;
}

void	ft_pop(t_list **stack)
{
	t_list	*prev;

	if (!(*stack))
		return ;
	prev = *stack;
	*stack = (*stack)->next;
	prev->content = NULL;
	prev->next = NULL;
	if (prev)
		free(prev);
	prev = NULL;
}

void	ft_swap(t_list **stack)
{
	void	*temp;

	if (!(*stack))
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	ft_push_from(t_list **from, t_list **to)
{
	if (!(*from) || !(*to))
		return ;
	ft_push(to, (*from)->content);
	ft_pop(from);
}

void	ft_rotate(t_list **stack)
{
	void	*temp;
	t_list	*ptr;

	if (!(*stack))
		return ;
	ptr = *stack;
	temp = (*stack)->content;
	while (ptr->next->next)
	{
		ptr->content = ptr->next->content;
		ptr = ptr->next;
	}
	ptr->content = temp;
}

void	ft_rrotate(t_list **stack)
{
	void	*curr;
	void	*next;
	t_list	*ptr;

	if (!(*stack))
		return (write(1, "Erro rrotate\n", 13), (void)0);
	ptr = *stack;
	curr = ptr->content;
	while (ptr->next->next)
	{
		next = ptr->next->content;
		ptr->next->content = curr;
		curr = next;
		ptr = ptr->next;
	}
	(*stack)->content = curr;
}


void	_get_stacks(t_list *a, t_list *b)
{
	printf("A:\n");
	ft_get_stack(a);
	printf("B:\n\n");
	ft_get_stack(b);
}
