/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:49:45 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/12 00:08:28 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stcknew(void *content)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	stack->idx = 0;
	stack->cost = 0;
	stack->target = -1;
	return (stack);
}

void	ft_push(t_stack **stack, void *content)
{
	t_stack	*node;
	int	push;

	push = 1;
	if (!(*stack))
		return (write(1, "Erro push\n", 10), (void)0);
		//return ;
	node = ft_stcknew(content);
	ft_update_idx(stack, push);
	node->next = *stack;
	*stack = node;
}

void	ft_pop(t_stack **stack)
{
	t_stack	*prev;
	int	pop;

	pop = 0;
	if (!(*stack))
		return (write(1, "Erro pop\n", 9), (void)0);
		//return ;
	prev = *stack;
	*stack = (*stack)->next;
	prev->content = NULL;
	prev->next = NULL;
	ft_update_idx(stack, pop);
	if (prev)
		free(prev);
	prev = NULL;
}

void	ft_swap(t_stack **stack)
{
	t_stack	temp;

	if (!(*stack))
		return (write(1, "Erro swap\n", 10), (void)0);
		//return ;
	temp = **stack;
	//printf("idx: %d | data: %ld -> idx: %d | data: %ld\n", (*stack)->idx, (long)(*stack)->content, (*stack)->next->idx, (long)(*stack)->next->content);
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp.content;
	//printf("idx: %d | data: %ld\n", (*stack)->idx, (long)(*stack)->content);
}

void	ft_push_from(t_stack **from, t_stack **to)
{
	if (!(*from) || !(*to))
		return (write(1, "Erro push_from\n", 15), (void)0);
		//return ;
	ft_push(to, (*from)->content);
	ft_pop(from);
}

void	ft_rotate(t_stack **stack)
{
	void	*temp;
	t_stack	*ptr;

	if (!(*stack))
		return (write(1, "Erro rotate\n", 12), (void)0);
		//return ;
	ptr = *stack;
	temp = ptr->content;
	while (ptr->next->next)
	{
		ptr->content = ptr->next->content;
		ptr = ptr->next;
	}
	ptr->content = temp;
}

void	ft_rrotate(t_stack **stack)
{
	void	*curr;
	void	*next;
	t_stack	*ptr;

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

void	ft_update_idx(t_stack **stack, int push)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		if (push)
			ptr->idx++;
		else
			ptr->idx--;
		ptr = ptr->next;
	}
}

void	_get_stacks(t_stack *a, t_stack *b)
{
	printf("A:\n");
	ft_get_stack(a);
	printf("B:\n\n");
	ft_get_stack(b);
}
