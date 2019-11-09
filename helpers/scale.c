/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:03:20 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 10:01:21 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	scale(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int		i;
	int		j;

	if (fdf->params.scale <= 0)
		return ;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			map[i][j].x *= fdf->params.scale;
			map[i][j].y *= fdf->params.scale;
			map[i][j].z *= fdf->params.scale;
			j++;
		}
		i++;
	}
}
