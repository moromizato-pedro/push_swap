/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:08:26 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/20 16:54:12 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_ft_get_stack(t_stack *stack)
{
	if (!stack)
		return ;
	printf("--------Stack:\n");
	while (stack)
	{
		if (stack->next)
			printf("	S[%d] %ld	-> %ld\n", stack->idx, (long)stack->data, (long)stack->next->data);
		else
			printf("	S[%d] %ld	-> %p\n", stack->idx, (long)stack->data, stack->next);
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*ft_create_stack(char **av)
{
	t_stack	*rev_stack;
	t_stack	*stack;

	if (!av || !(*av))
		return (NULL);
	rev_stack = NULL;
	stack = NULL;
	av++;
	//	Create reverse stack, because of stack First in-Last out nature
	while (*av)
	{
		ft_push(&rev_stack, (void *)(long)ft_atoi(*av));
		av++;
	}
	//_ft_get_stack(rev_stack);
	//	Creates the expected stack by pushing from the reversed stack
	while (rev_stack)
		ft_push_from(&rev_stack, &stack);
	//_ft_get_stack(stack);
	return (stack);
}

t_stack	*_ft_fill_stack(char *len_s)
{
	t_stack	*stack;
	t_stack	*rev_stack;
	int	len;

	if (!len_s)
		return (NULL);
	rev_stack = NULL;
	stack = NULL;
	srand(time(0));
	len = ft_atoi(len_s);
	//	Generate 'len' random numbers and insert inside the stack
	while (len-- > 0)
		ft_push(&rev_stack, (void *)(long)(rand() % 50));
	//	Creates the expected stack by pushing from the reversed stack
	while (rev_stack)
		ft_push_from(&rev_stack, &stack);
	return (stack);
}

