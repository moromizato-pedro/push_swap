/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:07:13 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/10/23 15:37:22 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dst);
	j = -1;
	if (size <= i)
		return (size + ft_strlen(src));
	while ((i + (++j)) < size - 1)
	{
		dst[i + j] = src[j];
		if (dst[i + j] == '\0')
			return (i + j);
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
