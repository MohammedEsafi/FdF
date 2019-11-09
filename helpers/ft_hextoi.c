/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:07 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 22:17:49 by tbareich         ###   ########.fr       */
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
	while (*hex != ' ' && i >= 0)
	{
		if (*hex >= '0' && *hex <= '9')
			integer += (*hex - '0') * pow(16, i);
		else if (*hex >= 'A' && *hex <= 'F')
			integer += (*hex - 'A' + 10) * pow(16, i);
		else if (*hex >= 'a' && *hex <= 'f')
			integer += (*hex - 'a' + 10) * pow(16, i);
		i--;
		hex++;
	}
	return (integer);
}
