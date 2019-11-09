/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:04:28 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 10:02:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	center(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int		i;
	int		j;
	int		w;
	int		h;

	w = ((W - MENU_W) - map[0][fdf->width - 1].x + map[fdf->height - 1][0].x) /
			2 - map[fdf->height - 1][0].x;
	h = (H - map[fdf->height - 1][fdf->width - 1].y +
			map[0][0].y) / 2 - map[0][0].y;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			map[i][j].y += h;
			map[i][j].x += w;
			j++;
		}
		i++;
	}
}
