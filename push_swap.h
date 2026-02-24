/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:17:30 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/24 20:02:31 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Delete those libraries
# include <stdio.h>

void	ft_push_swap(t_list **stack);
void	ft_push_from(t_list **from, t_list **to);
void	ft_push(t_list **stack, void *content);
void	ft_pop(t_list **stack);
void	ft_get_top(t_list *stack);
void	ft_get_stack(t_list *stack);

void	_get_stacks(t_list *a, t_list *b);

#endif
