/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:01:03 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/21 02:57:14 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <time.h>

//	Stack
typedef struct 		s_stack {
	void		*data;
	struct s_stack 	*next;
	int		idx;
	int		target;
	int		cost;
}			t_stack;

t_stack	*ft_stcknew(void *data);
void	ft_push(t_stack **stack, void *data);
void	ft_pop(t_stack **stack);
int	ft_is_sorted(t_stack *stack);
void	ft_reset_idxs(t_stack **stack);
int	ft_get_len(t_stack *stack);

//	Push
int	ft_isolate_3(t_stack **a, t_stack **b);
int	ft_order_3(t_stack **a);

//	Push_Utils
int	ft_parse_operation(char *op, t_stack **a, t_stack **b);
void	ft_push_from(t_stack **from, t_stack **to);
void	ft_swap_node(t_stack *node1, t_stack *node2);
void	ft_rotate(t_stack **stack);
void	ft_rrotate(t_stack **stack);

//	Turk Algorithm
int	ft_get_min_bigger(t_stack *stack, void *ref);
t_stack	ft_find_cheapest_node(t_stack **a, t_stack **b);
int	ft_sort_cheapest(t_stack **a, t_stack **b, t_stack cheapest);
int	ft_move_2_top(t_stack **a, t_stack **b, int cost_a, int cost_b);
int	ft_reorder_a(t_stack **a, int cost_a);
int	ft_turk_algorithm(t_stack **a, t_stack **b);

//	Turk Algorithm Utils
int	ft_cost_2_top(int idx, int len);
t_stack	ft_get_min_node(t_stack *a);
int	ft_abs(int n);
void	ft_update_costs(int *cost_a, int *cost_b);
int	ft_has_duplicate(t_stack *stack, void *data);
int	ft_get_min_duplicate(t_stack *stack, void *min_bigger);
int	ft_get_bigger(t_stack *stack);

//	Setup
void	_ft_get_stack(t_stack *stack);
t_stack	*ft_create_stack(char **av);
t_stack	*_ft_fill_stack(char *len_s);

#endif
