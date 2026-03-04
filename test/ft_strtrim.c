/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:30:17 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/03 18:52:52 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	char	*dup_start;
	char	*res;
	char	*aux;

	dup = ft_strdup(s1);
	if (!dup)
		return (NULL);
	dup_start = dup;
	aux = dup;
	while (*dup && ft_strchr(set, *dup))
		dup++;
	if (ft_strlen(dup) > 0)
		aux = dup + ft_strlen(dup) - 1;
	while (ft_strrchr(set, *aux))
	{
		*aux = '\0';
		aux--;
	}
	res = ft_strdup(dup);
	if (dup_start)
		free(dup_start);
	if (!res)
		return (NULL);
	return (res);
}
/*
int	main(void)
{
	char	*str = "   xxxtripouille   xxx";

	printf("str: %s | res: %s\n", str, /
			ft_strtrim("   xxxtripouille   xxx", " x"));
}
*/
