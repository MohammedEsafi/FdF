/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:07 by ael-makk          #+#    #+#             */
/*   Updated: 2019/11/06 00:35:44 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_hextoi(const char *hex)
{
	int		integer;
	int		i;

	if (hex == 0)
		return (0);
	i = 5;
	hex += 2;
	integer = 0;
	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			integer += (*hex - '0') * pow(16, i);
		else if (*hex >= 'A' && *hex <= 'F')
			integer += (*hex - 'A' + 10) * pow(16, i);
		i--;
		hex++;
	}
	return (integer);
}
