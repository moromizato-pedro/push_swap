/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:53:35 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/19 19:46:53 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuint_pf(unsigned int nbr, int *count)
{
	if (!count)
		return (-1);
	return (ft_putnbr_base_pf(nbr, "0123456789", count));
}
