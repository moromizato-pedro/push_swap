/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:41:36 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 16:14:21 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned int	i;

	if (dest == src)
		return (dest);
	i = -1;
	while (++i < count)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
/*
#include <string.h>

int	main(void)
{
	//void	*copy = NULL;
	void	*orig = NULL;

	//copy = ft_memcpy(NULL, NULL, 3);
	orig = memcpy(NULL, NULL, 3);
	//if (copy != orig)
	//	printf("copy != orig\n");
}*/
