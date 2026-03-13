/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:14:28 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/13 03:03:59 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse_operation(char *op, t_stack **a, t_stack **b)
{
	if (!op)
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
		return (write(1, "rrb\n", 4), ft_rrotate(b), 1);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		return (write(1, "rrr\n", 4), ft_rrotate(a), ft_rrotate(b), 1);
	else if (ft_strncmp(op, "ra", 2) == 0)
		return (write(1, "ra\n", 3), ft_rotate(a), 1);
	else if (ft_strncmp(op, "rb", 2) == 0)
		return (write(1, "rb\n", 3), ft_rotate(b), 1);
	else if (ft_strncmp(op, "rr", 2) == 0)
		return (write(1, "rr\n", 3), ft_rotate(a), ft_rotate(b), 1);
	return (write(1, "Erro\n", 5), 0);
}

void	test(t_stack **stack)
{
	t_stack	temp;

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

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
}

int	ft_stcklen(t_stack *stack)
{
	int	len;
	t_stack	*ptr;

	if (!stack)
		return (-1);
	len = 0;
	ptr = stack;
	while (ptr->next)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

int	ft_is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	if (stack->next)
		return (0);
	return (1);
}

int	ft_cost_to_top(int idx, int len)
{
	if (idx <= len / 2)
		return (idx);
	else
		return (-(len - idx));
}

int	ft_get_closest_bigger(t_stack *stack, void *src)
{
	t_stack	closest;

	if (!stack)
		return (-1);
	closest.content = (void *)INT_MAX;
	closest.idx = -1;
	//printf("src: %ld | closest.content: %ld | closest.idx: %d\n", (long)src, (long)closest.content, closest.idx);
	while (stack->next)
	{
		//printf("%ld > %ld ? %d | %ld <= %ld ? %d\n", (long)stack->content, (long)src, stack->content > src, (long)stack->content, (long)closest.content, stack->content <= closest.content);
		if (closest.content < src)
			closest.content = stack->content;
		if (stack->content > src && stack->content < closest.content)
			closest = *stack;
		//printf("closest.content: %ld | closest.idx: %d\n", (long)closest.content, closest.idx);
		stack = stack->next;
	}
	return (closest.idx);
}

int	ft_assign_closest_biggers(t_stack *target, t_stack **source)
{
	t_stack	*src;
	int	min_cost;
	int	total_cost;
	int	min_idx;

	if (!target || !source)
		return (-1);
	src = *source;
	min_idx = 0;
	min_cost = 0;
	printf("Assigning closest biggers\n");
	while (src->next)
	{
		src->target = ft_get_closest_bigger(target, src->content);
		printf("	target[%d]: %d\n", src->idx, src->target);
		total_cost = ft_abs(ft_cost_to_top(src->idx, ft_stcklen(*source)));
		if (src->target == -1)
			total_cost += 0;
		else
			total_cost += ft_abs(ft_cost_to_top(src->target, ft_stcklen(target)));
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			min_idx = src->idx;
		}
		src = src->next;
	}
	return (min_idx);
}

int	ft_count(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack->next->next)
	{
		if (stack)
			count++;
	}
	return (count);
}

void	ft_assign_cost(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack)
		return ;
	ptr = *stack;
	while (ptr->next->next)
	{
		ptr->cost = ft_cost_to_top(ptr->idx, ft_stcklen(*stack));
		printf("	[%d] %d\n", ptr->idx, ptr->cost);
		ptr = ptr->next;
	}
}

int	ft_divide(t_stack **a, t_stack **b)
{
	int	operations;

	if (!a || !b)
		return (0);
	operations = 0;
	while ((*a)->next->next->next->next)
		operations += ft_parse_operation("pb", a, b);
	return (operations);
}

int	ft_is_sorted(t_stack *a, int rev)
{
	if (!a)
		return (1);
	while (a->next->next)
	{
		//printf("content > next (%ld < %ld) ? %d\n", (long)a->content, (long)a->next->content, a->content > a->next->content);
		if (a->content > a->next->content && !rev)
			return (printf("!sorted\n"), 0);
		if (a->content < a->next->content && rev)
			return (printf("!sorted\n"), 0);
		a = a->next;
	}
	return (printf("sorted\n"), 1);
}

int	ft_sort_3(t_stack **stack)
{
	t_stack	*ptr;
	int	i;
	int	j;
	int	operations;
	int	rev;

	if (!stack)
		return (0);
	i = -1;
	j = -1;
	operations = 0;
	rev = 1;
	ptr = *stack;
	while (++i < 3 && !ft_is_sorted(*stack, !rev))
	{
		ptr = *stack;
		while(++j < 3 && !ft_is_sorted(*stack, !rev))
		{
			if (ptr->content > ptr->next->content)
				operations += ft_parse_operation("sa", stack, NULL);
			ft_get_stack(*stack);
			if (!ft_is_sorted(*stack, !rev))
				operations += ft_parse_operation("rra", stack, NULL);
			ptr = ptr->next;
		}
	}
	return (operations);
}

//	TODO: 	Create sorting algorithm (Turk sort), implementing the total cost calculation and associated operations
//		No tests were made for assigning costs, nor assigning smaller biggers!
//	ft_sort_stack

t_stack	*ft_get_node_by_index(t_stack *stack, int idx)
{
	t_stack *ptr;

	ptr = stack;
	while (ptr->next)
	{
		if (ptr->idx == idx)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int	ft_move2top(t_stack **stack, char id, int iters)
{
	int	rev;
	int	i;
	int	operations;

	if (!stack)
		return (0);
	operations = 0;
	rev = 0;
	if (iters < 0)
		rev = 1;
	i = ft_abs(iters);
	printf("iters: %d | rev: %d\n", iters, rev);
	while (i-- > 0)
	{
		if (id == 'a' && rev)
			operations += ft_parse_operation("rra", stack, NULL);
		else if (id == 'a' && !rev)
			operations += ft_parse_operation("ra", stack, NULL);
		else if (id == 'b' && rev)
			operations += ft_parse_operation("rrb", NULL, stack);
		else if (id == 'b' && !rev)	
			operations += ft_parse_operation("rb", NULL, stack);
	}
	return (operations);
}

int	ft_move_target(t_stack **a, t_stack **b, t_stack *target)
{
	int	i;
	int	operations;

	operations = 0;
	printf("	Move_target (b): %d\n", target->idx);
	ft_get_stack(*b);
	i = ft_cost_to_top(target->idx, ft_stcklen(*b));
	operations += ft_move2top(b, 'b', i);
	printf("\n");
	ft_get_stack(*b);
	printf("	Move_target (a): %d\n", target->target);
	ft_get_stack(*a);
	if (target->target == -1)
	{
		printf("target = -1\n");
		operations += ft_parse_operation("pa", a, b);
		operations += ft_move2top(a, 'a', 1);
	}
	else
	{
		i = ft_cost_to_top(target->target, ft_stcklen(*a));
		operations += ft_move2top(a, 'a', i);
		operations += ft_parse_operation("pa", a, b);
		printf("\n");
		ft_get_stack(*a);
		printf("	Returning_target (a)\n");
		ft_get_stack(*a);
		printf("\n");
		if (i < 0)
			operations += ft_move2top(a, 'a', -i + 1);
		else
			operations += ft_move2top(a, 'a', -i);
		ft_get_stack(*a);
	}
	printf("\n\n");
	return (operations);
}

int	ft_get_min_idx(t_stack *stack)
{
	t_stack	min;
	t_stack *ptr;

	ptr = stack;
	min = *ptr;
	while (ptr->next)
	{
		if (ptr->content < min.content)
			min = *ptr;
	}
	return (min.idx);
}

int	ft_turk_sort(t_stack **a, t_stack **b)
{
	int	target_idx;
	int	rot_iters;
	int	operations;

	operations = 0;
	while (!ft_is_empty(*b))
	{
		//ft_assign_cost(a);
		//ft_assign_cost(b);
		//printf("Costs assigned\n");
		target_idx = ft_assign_closest_biggers(*a, b);
		printf("idx: %d\n", target_idx);
		_get_stacks(*a, *b);
		operations += ft_move_target(a, b, ft_get_node_by_index(*b, target_idx));
		_get_stacks(*a, *b);
	}
	/*rot_iters = ft_abs(ft_cost_to_top(ft_get_min_idx(*a), ft_stcklen(*a)));
	while (rot_iters > 0)
	{
		if (ft_cost_to_top(ft_get_min_idx(*a), ft_stcklen(*a) < 0))
			operations += ft_parse_operation("rra", a, NULL);
		else
			operations += ft_parse_operation("ra", a, NULL);
	}*/
	return (operations);
}

int	ft_is_top_higher(t_stack *a, int rev)
{
	if (!a)
		return (0);
	if (a->content > a->next->content && !rev)
		return (1);
	else if (a->content < a->next->content && rev)
		return (1);
	return (0);
}

int	ft_transfer_a(t_stack **a, t_stack **b)
{
	int	operations;

	operations = 0;
	while ((*b)->next)
		operations += ft_parse_operation("pa", a, b);
	return (operations);
}

void	ft_push_swap(t_stack **a)
{
	int	operations;
	t_stack	*b;

	operations = 0;
	b = ft_stcknew(NULL);
	//test(a);
	_get_stacks(*a, b);
	printf("\n###### Instructions: ######\n");
	operations += ft_divide(a, &b);
	operations += ft_sort_3(a);
	_get_stacks(*a, b);
	operations += ft_turk_sort(a, &b);
	printf("###########################\n");
	_get_stacks(*a, b);
	ft_is_sorted(*a, 0);
	//ft_is_sorted(b, 1);
	printf("Operations: %d\n", operations);
}

# include <time.h>

void	ft_get_top(t_stack *stack);
void	ft_get_stack(t_stack *stack);
void	ft_fill_stack(int size, t_stack **stack);
void	ft_clear_stack(t_stack **stack);

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		size;

	srand(time(NULL));
	stack = ft_stcknew(NULL);
	stack->idx = 0;
	stack->cost = 0;
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

void	ft_fill_stack(int size, t_stack **stack)
{
	if (size < 0)
		return ;
	while (size-- > 0)
		ft_push(stack, (void *)(long)(rand()%50));
}

void	ft_get_top(t_stack *stack)
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

void	ft_get_stack(t_stack *stack)
{
	int	depth;

	if (!stack)
		return ;
	depth = 0;
	while (stack)
	{
		printf("		[%d] content: %ld \n", stack->idx, (long)stack->content);
		//if (stack->content)
		//	printf("		[%d] content: %ld \n", depth++, (long)stack->content);
		//else
		//	printf("		[%d] content: %p \n", depth++, stack->content);
		stack = stack->next;
	}
}

void	ft_clear_stack(t_stack **stack)
{
	if (!stack)
		return ;
	while (*stack)
		ft_pop(stack);
}

