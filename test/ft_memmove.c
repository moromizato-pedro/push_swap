/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:50:57 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 21:12:02 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}
/*
#include <string.h>

//printf("d[%zu]: %c | s[%zu]: %c | d: %s\n", i, d[i], i, s[i], d);
int	main(void)
{
	char	str2[12] = "Hello World";

	
	printf("%s\n", str2);
	ft_memmove(str2 + 4, str2, sizeof(char) * 5);
	printf("%s\n", str2);
}
*/
