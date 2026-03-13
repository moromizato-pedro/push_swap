/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:17:30 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/03/12 20:57:27 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

// Delete those libraries
# include <stdio.h>

typedef struct	s_stack
{
	void		*content;
	struct s_stack	*next;
	int		idx;
	int		cost;
	int		target;
}		t_stack;

t_stack	*ft_stcknew(void *content);
void	ft_push_swap(t_stack **stack);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack, void *content);
void	ft_push_from(t_stack **from, t_stack **to);
void	ft_pop(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_rrotate(t_stack **stack);
void	ft_get_top(t_stack *stack);
void	ft_get_stack(t_stack *stack);
void	ft_update_idx(t_stack **stack, int push);

void	_get_stacks(t_stack *a, t_stack *b);

#endif
