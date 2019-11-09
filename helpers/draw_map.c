/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 02:43:53 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 10:02:26 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			// if (((map[i][j].x >= 0 && map[i][j].x <= fdf->width) || (map[i][j + 1].x >= 0 && map[i][j + 1].x <= fdf->width)) && 
			// ((map[i][j].y >= 0 && map[i][j].y <= fdf->height) || (map[i][j + 1].y >= 0 && map[i][j + 1].y <= fdf->height)))
			// {
				if (j + 1 < fdf->width)
					draw_line(fdf, map[i][j], map[i][j + 1]);
			// }
			// if (((map[i][j].x >= 0 && map[i][j].x <= fdf->width) || (map[i + 1][j].x >= 0 && map[i + 1][j].x <= fdf->width)) && 
			// ((map[i][j].y >= 0 && map[i][j].y <= fdf->height) || (map[i + 1][j].y >= 0 && map[i + 1][j].y <= fdf->height)))
			// {
				if (i + 1 < fdf->height)
					draw_line(fdf, map[i][j], map[i + 1][j]);
			// }
			j++;
		}
		i++;
	}
}
