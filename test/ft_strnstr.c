/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:54:53 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/10/23 16:52:26 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] && i < n)
	{
		j = 0;
		while ((i + j) < n && big[i + j] == little[j]
			&& little[j] != '\0' && big[i + j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
	}
	return (0);
}
