/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 23:27:26 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/05 23:49:58 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0 && n > -10)
		ft_putchar_fd('-', fd);
	if (n < 0)
		ft_putchar_fd((n % 10) * -1 + '0', fd);
	else
		ft_putchar_fd(n % 10 + '0', fd);
}
