/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:53:30 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/10/23 16:10:25 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		idx;

	idx = -1;
	ptr = 0;
	while (str[++idx])
	{
		if (str[idx] == (char)c)
			ptr = &((char *)str)[idx];
	}
	if ((char)c == '\0')
		ptr = &((char *)str)[idx];
	return (ptr);
}
