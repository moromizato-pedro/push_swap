/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:38:04 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 23:46:12 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;

	ptr = NULL;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (nmemb * size > SIZE_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	char	**split;

	split = (char **)ft_calloc(sizeof(char *), 2);
	if (split)
		free(split);
	return (0);
}
*/
