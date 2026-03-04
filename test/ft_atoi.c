/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:00:46 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/10/23 16:05:34 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_char(const char *str, int *is_nbr, int *is_sign, int *res)
{
	int		idx;
	char	c;

	idx = -1;
	while (str[++idx])
	{
		c = str[idx];
		if (c >= '0' && c <= '9')
		{
			*res *= 10;
			*res += c - '0';
			*is_nbr = 1;
		}
		else if ((c >= 9 && c <= 13) || c == 32 || c == '-' || c == '+')
		{
			if (*is_nbr || *is_sign)
				break ;
			else if (c == '+')
				*is_sign = 1;
			else if (c == '-')
				*is_sign = -1;
		}
		else
			break ;
	}
}

int	ft_atoi(const char *str)
{
	int	is_nbr;
	int	is_sign;
	int	res;

	is_nbr = 0;
	is_sign = 0;
	res = 0;
	check_char(str, &is_nbr, &is_sign, &res);
	if (is_sign)
		return (res * is_sign);
	else
		return (res);
}
