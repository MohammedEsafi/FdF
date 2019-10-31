/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:09:44 by tbareich          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:12 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		ft_hextoi(const char *hex)
{
	int		integer;
	int		i;

	if (hex == 0)
		return (0);
	i = 0;
	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			integer = (*hex - '0') * pow(16, i);
		else
			integer = (*hex - 'A') * pow(16, i);
		i++;
		hex++;
	}
	return (integer);
}
