/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:08:26 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/30 23:36:35 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		n = 0;
		while (arr[n])
			n++;
	}
	if (!ft_validate_params(n, arr))
		return (NULL);
	while (n-- > 0)
		ft_push(&rev_stack, (void *)(long)ft_atoi(*(arr++)));
	while (rev_stack)
		ft_push_from(&rev_stack, &stack);
	return (stack);
}

//	Checks if the string is empty
//	If not, verify if every char is a digit
//	Ignores only if the first char is a - or + sign followed by a digit
//	Then check if the number resulted from the string is within int limits
int	ft_validate_params(int n, char **av)
{
	long long	nbr;
	int			i;
	int			j;

	i = 0;
	while (n-- > 0)
	{
		j = 0;
		if (ft_strlen(av[i]) == 0)
			return (0);
		if (ft_strlen(av[i]) >= 2 && (av[i][j] == '-' || av[i][j] == '+'))
			j++;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (0);
		nbr = ft_atoi_push(av[i++]);
		if (nbr > (long long)INT_MAX || nbr < (long long)INT_MIN)
			return (0);
	}
	return (1);
}

//	Uses long long to be able to further check for integer limits breaches
long long	ft_atoi_push(char *str)
{
	int			is_nbr;
	int			is_sign;
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

void	ft_check_char(const char *str, int *is_nbr, int *is_sgn, long long *res)
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
			if (*is_nbr || *is_sgn)
				break ;
			else if (c == '+')
				*is_sgn = 1;
			else if (c == '-')
				*is_sgn = -1;
		}
		else
			break ;
	}
}
/*
void	_ft_get_stack(t_stack *stack)
{
	if (!stack)
		return ;
	printf("--------Stack:\n");
	while (stack)
	{
		if (stack->next)
			printf("	S[%d] %ld	-> %ld\n", /
			stack->idx, (long)stack->data, (long)stack->next->data);
		else
			printf("	S[%d] %ld	-> %p\n", /
			stack->idx, (long)stack->data, stack->next);
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
		ft_push(&rev_stack, (void *)(long)(rand() % 100 - 50));
	while (rev_stack)
		ft_push_from(&rev_stack, &stack);
	return (stack);
}
*/
