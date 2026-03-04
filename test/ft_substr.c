/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:41:18 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/06 00:08:12 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*sub;
	size_t			i;

	s_len = ft_strlen(s);
	i = -1;
	if (start < s_len)
	{
		if (s_len - start + 1 <= len)
			sub = (char *)malloc(sizeof(char) * (s_len + 1 - start));
		else
			sub = (char *)malloc(sizeof(char) * (len + 1));
	}
	else
		sub = malloc(1);
	if (!sub)
		return (NULL);
	while (++i < len && (start + i) < s_len)
	{
		sub[i] = s[start + i];
	}
	sub[i] = '\0';
	return (sub);
}
