/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:08:26 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/23 02:51:44 by pedrohe3         ###   ########.fr       */
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

t_stack	*ft_get_params(t_stack *stack)
{
	t_stack	*copy;
	t_stack	*rev_copy;

	copy = NULL;
	rev_copy = NULL;
	while (stack)
	{
		ft_push(&rev_copy, stack->data);
		stack = stack->next;
	}
	while (rev_copy)
		ft_push_from(&rev_copy, &copy);
	return (copy);
}

//	Create reverse stack, because of stack First in-Last out nature, then
//	creates the expected stack by pushing from the reversed stack
t_stack	*ft_create_stack(int n, char **av)
{
	t_stack	*rev_stack;
	t_stack	*stack;
	char	**arr;

	if (!av || !(*av))
		return (NULL);
	rev_stack = NULL;
	stack = NULL;
	arr = av + 1;
	if (n == 1)
	{
		arr = ft_split(*arr, ' ');
		while (arr[n])
			n++;
	}
	if (!ft_validate_params(n, arr))
		return (stack);
	while (n-- > 0)
	{
		ft_push(&rev_stack, (void *)(long)ft_atoi(*arr));
		arr++;
	}
	while (rev_stack)
		ft_push_from(&rev_stack, &stack);
	return (stack);
}

//	Generate 'len' random numbers and insert inside the stack
//	Creates the expected stack by pushing from the reversed stack
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
	while (len-- > 0)
		ft_push(&rev_stack, (void *)(long)(rand() % 50));
	while (rev_stack)
		ft_push_from(&rev_stack, &stack);
	return (stack);
}

int	ft_validate_params(int n, char **av)
{
	int		i;
	int		j;
	long long	nbr;

	i = 0;
	while (n-- > 0)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				if (j == 0 && (av[i][j] != '-' && av[i][j] != '+'))
					return (0);
			j++;
		}
		nbr = ft_atoi_push(av[i]);
		if (nbr > (long long)INT_MAX  || nbr < (long long)INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi_push(char *str)
{
	int		is_nbr;
	int		is_sign;
	long long	res;

	is_nbr = 0;
	is_sign = 0;
	res = 0;
	ft_check_char(str, &is_nbr, &is_sign, &res);
	if (is_sign)
		return (res * is_sign);
	else
		return (res);
}

void	ft_check_char(const char *str, int *is_nbr, int *is_sign, long long *res)
{
	int		idx;
	char	c;

	idx = -1;
	while (str[++idx])
	{
		c = str[idx];
		if (c >= '0' && c <= '9')
		{
			*res *= 10;
			*res += c - '0';
			*is_nbr = 1;
		}
		else if ((c >= 9 && c <= 13) || c == 32 || c == '-' || c == '+')
		{
			if (*is_nbr || *is_sign)
				break ;
			else if (c == '+')
				*is_sign = 1;
			else if (c == '-')
				*is_sign = -1;
		}
		else
			break ;
	}
}

