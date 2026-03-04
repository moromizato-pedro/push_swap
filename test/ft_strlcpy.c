/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:39:25 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/10/29 18:22:08 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	int		len;

	len = 0;
	idx = -1;
	while (src[len])
		len++;
	if (size <= 0)
		return (len);
	while (src[++idx] && idx < size - 1)
		dst[idx] = src[idx];
	dst[idx] = '\0';
	return (len);
}
