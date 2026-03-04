/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:53:14 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/03 18:53:23 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	digits;

	digits = 0;
	while (1)
	{
		digits++;
		if (n / 10 == 0)
			break ;
		n /= 10;
	}
	return (digits);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;

	len = ft_countdigits(n);
	if (n < 0)
		len++;
	i = len;
	res = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	while (1)
	{
		res[i - 1] = '0' + ft_abs(n % 10);
		n /= 10;
		if (n == 0)
			break ;
		i--;
	}
	return (res);
}
/*
#include <limits.h>

int	main(void)
{
	int	i = 0;

	printf("i: %d | n: %s\n", i, ft_itoa(i));
	return (0);
}
*/
