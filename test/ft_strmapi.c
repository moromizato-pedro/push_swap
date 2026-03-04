/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:25:06 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/05 19:41:26 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	int		len;
	int		i;

	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	len = ft_strlen(dup);
	i = -1;
	while (++i < len)
		dup[i] = (*f)(i, dup[i]);
	return (dup);
}
