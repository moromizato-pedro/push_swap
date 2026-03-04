/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:51:15 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/06 01:33:33 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **split)
{
	char	**start;

	start = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(start);
}

static int	ft_countwords(char const *s, char c)
{
	int	is_word;
	int	words;

	words = 0;
	is_word = 0;
	while (*s)
	{
		if (!is_word && *s != c)
			is_word = 1;
		else if (is_word && *s == c)
		{
			is_word = 0;
			words++;
		}
		s++;
	}
	if (is_word)
		words++;
	return (words);
}

static int	ft_sep_strlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
			len++;
		else if (len > 0 && *s == c)
			break ;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;
	int		words;
	int		i;

	words = ft_countwords(s, c);
	split = (char **)ft_calloc(sizeof(char *), words + 1);
	if (!split)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = ft_sep_strlen(s, c);
		split[i] = ft_substr(s, 0, len);
		if (!split[i])
			return (ft_free_split(split), NULL);
		s += len;
	}
	split[i] = NULL;
	return (split);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**arr;
	char	**aux;
	char	*str = "hello!";
	char	sep = ' ';

	arr = ft_split(str, sep);
	aux = arr;
	while (*aux)
	{
		printf("arr: %s\n", *aux);
		free(*aux);
		aux++;
	}
	free(arr);
	return (0);
}
*/
