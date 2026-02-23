/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:14:28 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/23 19:27:15 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	push_swap(t_list a)
{
	t_list	b;

}
*/	

#include <stdio.h>
#include <time.h>

void	ft_get_top(t_list *stack);
void	ft_get_stack(t_list *stack);
void	ft_fill_stack(int size, t_list **stack, void (*add_func)(t_list**, t_list*));

int	main(int ac, char **av)
{
	t_list	*stack;
	int		size;

	srand(time(NULL));
	stack = ft_lstnew(NULL);
	if (ac > 1)
	{
		size = ft_atoi(av[1]);
		ft_fill_stack(size, &stack, ft_push);
		printf("av: %s\n", av[1]);
		ft_get_stack(stack);
		ft_get_top(stack);
		ft_pop(stack);
		ft_get_stack(stack);
		ft_get_top(stack);
		printf("END\n");
	}
	return (0);
}

void	ft_fill_stack(int size, t_list **stack, void (*add_func)(t_list **, t_list *))
{
		while (size-- > 0)
			add_func(stack, ft_lstnew((void *)(long)(rand()%50)));
}

void	ft_get_top(t_list *stack)
{
	if (stack->content)
		printf("[top] content: %ld |", (long)stack->content);
	else
		printf("[top] content: %p |", stack->content);
	printf("next: %p \n", stack->next);
}

void	ft_get_stack(t_list *stack)
{
	int	depth;

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

