/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 02:43:53 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 22:07:46 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// static checker(t_point start, t_point end)
// {
// 	int		ret;

// 	ret = 0;
// 	if (map[i][j].x >= 0 && map[i][j].x <= (W - MENU_W))
// 		ret++;
	
// }

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
			if (j + 1 < fdf->width && (map[i][j].x >= 0 || map[i][j + 1].x >= 0) && (map[i][j].y >= 0 || map[i][j + 1].y >= 0) && (map[i][j].x <= (W - MENU_W) || map[i][j + 1].x <= (W - MENU_W)) && (map[i][j].y <= (W - MENU_W) || map[i][j + 1].y <= (W - MENU_W)))
				draw_line(fdf, map[i][j], map[i][j + 1]);
			if (i + 1 < fdf->height && (map[i][j].x >= 0 || map[i + 1][j].x >= 0) && (map[i][j].y >= 0 || map[i + 1][j].y >= 0) && (map[i][j].x <= (W - MENU_W) || map[i + 1][j].x <= (W - MENU_W)) && (map[i][j].y <= (W - MENU_W) || map[i + 1][j].y <= (W - MENU_W)))
				draw_line(fdf, map[i][j], map[i + 1][j]);
			j++;
		}
		i++;
	}
}
