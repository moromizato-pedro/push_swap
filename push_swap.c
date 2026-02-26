/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:14:28 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/26 03:56:03 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse_operation(char *op, t_list **a, t_list **b)
{
	if (!op || !a || !b)
		return (write(1, "Erro\n", 5), 0);
	if (ft_strncmp(op, "sa", 2) == 0)
		return (write(1, "sa\n", 3), ft_swap(a), 1);
	else if (ft_strncmp(op, "sb", 2) == 0)
		return (write(1, "sb\n", 3), ft_swap(b), 1);
	else if (ft_strncmp(op, "ss", 2) == 0)
		return (write(1, "ss\n", 3), ft_swap(a), ft_swap(b), 1);
	else if (ft_strncmp(op, "pa", 2) == 0)
		return (write(1, "pa\n", 3), ft_push_from(b, a), 1);
	else if (ft_strncmp(op, "pb", 2) == 0)
		return (write(1, "pb\n", 3), ft_push_from(a, b), 1);
	else if (ft_strncmp(op, "rra", 3) == 0)
		return (write(1, "rra\n", 4), ft_rrotate(a), 1);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		return (write(1, "rrb\n", 4), ft_rrotate(a), 1);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		return (write(1, "rrr\n", 4), ft_rrotate(a), ft_rrotate(b), 1);
	else if (ft_strncmp(op, "ra", 2) == 0)
		return (write(1, "ra\n", 3), ft_rotate(a), 1);
	else if (ft_strncmp(op, "rb", 2) == 0)
		return (write(1, "rb\n", 3), ft_rotate(a), 1);
	else if (ft_strncmp(op, "rr", 2) == 0)
		return (write(1, "rr\n", 3), ft_rotate(a), ft_rotate(b), 1);
	return (write(1, "Erro\n", 5), 0);
}

void	test(t_list **stack)
{
	t_list	temp;

	temp = **stack;
	printf("\n\nTesting\n\n");
	printf("**stack: %lu | *stack: %lu | stack: %lu\n", sizeof(**stack), sizeof(*stack), sizeof(stack));
	printf("&(**stack): %p | &(*stack): %p | &(stack): %p\n", &(**stack), &(*stack), &(stack));
	printf("*stack: %p | stack: %p\n", *stack, stack);
	printf("(**stack).content: %ld | (**stack).next: %p\n", (long)(**stack).content, (**stack).next);
	printf("*stack->:content: %ld | *stack->next: %p\n", (long)(*stack)->content, (*stack)->next);
	
	temp.content--;
	printf("\n\ntemp.content: %ld | temp.next: %p\n", (long)temp.content, temp.next);
	printf("\n\nEnd Testing\n\n");
}

long	ft_get_max(t_list *a)
{
	long	max;

	max = INT_MIN; 
	while (a->next)
		if (max < (long)a->content)
			max = (long)a->content;
	return (max);
}

int	ft_count(t_list *a)
{
	int	count;

	if (!a)
		return (0);
	count = 1;
	while (a->next)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	ft_divide(t_list **a, t_list **b)
{
	int	half;
	int	operations;

	operations = 0;
	half = ft_count(*a) / 2;
	while (half-- > 0)
		operations += ft_parse_operation("pb", a, b);
	return (operations);
}

int	ft_is_sorted(t_list *a)
{
	void	*min;
	int	count;

	count = ft_count(a);
	min = a->content;
	//printf("min: %ld | count: %d\n", (long)min, count);
	while (a->next)
	{
	//	printf("a->content < min (%ld < %ld) ? %d\n", (long)a->content, (long)min, a->content < min);
		if (a->content < min)
			//return (printf("!sorted\n"), 0);
			return (0);
		a = a->next;
	}
	//return (printf("sorted\n"), 1);
	return (1);
}

int	ft_sort_stacks(t_list **a, t_list **b)
{
	int	operations;

	operations = 0;
	while (!ft_is_sorted(*a) || !ft_is_sorted(*b))
	{
		if ((*a)->content > (*a)->next->content && \
				(*b)->content > (*b)->next->content)
			operations += ft_parse_operation("ss", a, b);
		else if ((*a)->content > (*a)->next->content)
			operations += ft_parse_operation("sa", a, b);
		else if ((*b)->content > (*b)->next->content)
			operations += ft_parse_operation("sb", a, b);
		if (!ft_is_sorted(*a) && !ft_is_sorted(*b))
			operations += ft_parse_operation("rrr", a, b);
		else if (!ft_is_sorted(*a))
			operations += ft_parse_operation("rra", a, b);
		else if (!ft_is_sorted(*b))
			operations += ft_parse_operation("rrb", a, b);
		//_get_stacks(*a, *b);
	}
	return (operations);
}

void	ft_push_swap(t_list **a)
{
	t_list	*b;
	int	operations;

	operations = 0;
	b = ft_lstnew(NULL);
	//test(a);
	operations += ft_divide(a, &b);
	_get_stacks(*a, b);
	printf("\n###### Instructions: ######\n");
	operations += ft_sort_stacks(a, &b);
	printf("###########################\n");
	printf("Operations: %d\n", operations);
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
	//if (stack->content)
	//	printf("[top] content: %ld |", (long)stack->content);
	//else
	//	printf("[top] content: %p |", stack->content);
	printf("[top] content: %ld |", (long)stack->content);
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
		printf("		[%d] content: %ld \n", depth++, (long)stack->content);
		//if (stack->content)
		//	printf("		[%d] content: %ld \n", depth++, (long)stack->content);
		//else
		//	printf("		[%d] content: %p \n", depth++, stack->content);
		stack = stack->next;
	}
}

void	ft_clear_stack(t_list **stack)
{
	if (!stack)
		return ;
	while (*stack)
		ft_pop(stack);
}

