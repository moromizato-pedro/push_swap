/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:14:28 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/24 20:23:47 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_parse_operation(char *op, t_list **a, t_list **b)
{
	if (ft_strcmp(op, "sa") == 0)
		ft_swap(a);
	else if (ft_strcmp(op, "sb" == 0))
		ft_swap(b);
	else if (ft_strcmp(op, "ss" == 0))
		return (ft_swap(a), ft_swap(b));
	else if (ft_strcmp(op, "pa" == 0))
		ft_push_from(b, a);
	else if (ft_strcmp(op, "pb" == 0))
		ft_push_from(a, b);
	else if (ft_strcmp(op, "ra" == 0))
		ft_rotate(a);
	else if (ft_strcmp(op, "rb" == 0))
		ft_rotate(a);
	else if (ft_strcmp(op, "rr" == 0))
		return (ft_rotate(a), ft_rotate(b));
	else if (ft_strcmp(op, "rra" == 0))
		ft_rrotate(a);
	else if (ft_strcmp(op, "rrb" == 0))
		ft_rrotate(a);
	else if (ft_strcmp(op, "rrr" == 0))
		return (ft_rrotate(a), ft_rrotate(b));
}
*/

void	ft_push_swap(t_list **a)
{
	t_list	*b;

	b = ft_lstnew(NULL);
	_get_stacks(*a, b);
	ft_push_from(a, &b);
	_get_stacks(*a, b);
}

# include <time.h>

void	ft_get_top(t_list *stack);
void	ft_get_stack(t_list *stack);
void	ft_fill_stack(int size, t_list **stack);
void	ft_clear_stack(t_list **stack);

int	main(int ac, char **av)
{
	t_list	*stack;
	int		size;

	srand(time(NULL));
	stack = ft_lstnew(NULL);
	if (ac > 1)
	{
		size = ft_atoi(av[1]);
		ft_fill_stack(size, &stack);
		printf("av: %s\n", av[1]);
		ft_push_swap(&stack);
		printf("END\n\n");
	}
	return (0);
}

void	ft_fill_stack(int size, t_list **stack)
{
	if (size < 0)
		return ;
	while (size-- > 0)
		ft_push(stack, (void *)(long)(rand()%50));
}

void	ft_get_top(t_list *stack)
{
	if (!stack)
		return ;
	if (stack->content)
		printf("[top] content: %ld |", (long)stack->content);
	else
		printf("[top] content: %p |", stack->content);
	printf("next: %p \n", stack->next);
}

void	ft_get_stack(t_list *stack)
{
	int	depth;

	if (!stack)
		return ;
	depth = 0;
	while (stack)
	{
		if (stack->content)
			printf("		[%d] content: %ld \n", depth++, (long)stack->content);
		else
			printf("		[%d] content: %p \n", depth++, stack->content);
		stack = stack->next;
	}
}

void	ft_clear_stack(t_list **stack)
{
	t_list	*prev;

	if (!stack)
		return ;
	while (*stack)
		ft_pop(stack);
}

