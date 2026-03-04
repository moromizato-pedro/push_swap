/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:38:26 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/10/23 16:08:34 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		idx;

	idx = -1;
	ptr = 0;
	while (str[++idx])
	{
		if (str[idx] == (char)c)
		{
			ptr = &((char *)str)[idx];
			break ;
		}
	}
	if ((char)c == '\0')
		ptr = &((char *)str)[idx];
	return (ptr);
}
