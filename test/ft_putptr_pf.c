/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:42:09 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/19 19:46:37 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_pf(long addr, int *count)
{
	if (!count)
		return (-1);
	if (!addr)
		return (ft_putstr_pf("(nil)", count));
	ft_putstr_pf("0x", count);
	ft_putnbr_base_pf(addr, "0123456789abcdef", count);
	return (1);
}
