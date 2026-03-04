/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:57:35 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 22:34:02 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <string.h>

int	main(void)
{

	t_list *l = ft_lstnew(strdup("nyacat"));
 	t_list *n = ft_lstnew(strdup("OK"));
 
 	ft_lstadd_front(&l, n);
 	if (l == n && !strcmp(l->content, "OK"))
 	{
		printf("l: %s | next: %s\n", (char *)l->content,
			(char *)l->next->content);
 		printf("TEST_SUCCESS\n");
 	}
	else
		printf("TEST_FAILED\n");


	t_list *l = ft_lstnew(ft_strdup("nyacat"));
 	t_list *n = ft_lstnew(ft_strdup("OK"));

 	ft_lstadd_front(&l, n);
 	if (l == n && !strcmp(l->content, "OK"))
 	{
		printf("l: %s | next: %s\n", (char *)l->content,
			(char *)l->next->content);
 		free(l->next);
 		free(l);
 		printf("TEST_SUCCESS\n");
 	}
	else
	{
 		free(l->next);
 		free(l);
 		printf("TEST_FAILED\n");
	}
}
*/
