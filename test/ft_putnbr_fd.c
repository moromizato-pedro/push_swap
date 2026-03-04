/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:02:04 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/03 18:19:23 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10 != 0)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	ft_putchar_fd('0' + (char)ft_abs(n % 10), fd);
}
/*
#include <limits.h>

int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
}
*/
