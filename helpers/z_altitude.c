/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_altitude.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 05:13:58 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 10:01:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	z_altitude(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (map[i][j].z != 0)
				map[i][j].z += fdf->params.z_alt;
			j++;
		}
		i++;
	}
}
