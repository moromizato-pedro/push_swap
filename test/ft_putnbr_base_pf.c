/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:36 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/19 19:45:48 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_pf(long nbr, char *base, int *count)
{
	unsigned long	len;
	unsigned long	n;

	n = (unsigned long)nbr;
	if (!base || !count)
		return (-1);
	len = ft_strlen(base);
	if (nbr < 0 && len == 10)
	{
		ft_putchar_pf('-', count);
		n = (unsigned long)-nbr;
	}
	if (n >= len)
		ft_putnbr_base_pf(n / len, base, count);
	return (ft_putchar_pf(base[n % len], count));
}
