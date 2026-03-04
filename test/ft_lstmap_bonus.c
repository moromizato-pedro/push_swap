/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:32:52 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 22:33:01 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	copy = NULL;
	while (lst)
	{
		if (f)
			content = f(lst->content);
		else
			content = lst->content;
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&copy, del);
			return (NULL);
		}
		ft_lstadd_back(&copy, node);
		lst = lst->next;
	}
	return (copy);
}
