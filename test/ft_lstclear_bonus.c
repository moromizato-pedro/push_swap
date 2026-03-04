/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:58:19 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 21:51:18 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*aux;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}
