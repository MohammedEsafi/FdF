/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:07 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 08:41:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_hexlen(const char *hex)
{
	int		count;

	count = -1;
	while (((*hex >= '0' && *hex <= '9') || (*hex >= 'A' && *hex <= 'F')
				|| (*hex >= 'a' && *hex <= 'f')))
	{
		count++;
		hex++;
	}
	return (count);
}

int		ft_hextoi(const char *hex)
{
	int		integer;
	int		i;

	if (hex == 0)
		return (0);
	hex += 2;
	i = ft_hexlen(hex);
	integer = 0;
	while (i >= 0)
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
