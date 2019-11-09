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
			if (j + 1 < fdf->width)
				draw_line(fdf, map[i][j], map[i][j + 1]);
			if (i + 1 < fdf->height)
				draw_line(fdf, map[i][j], map[i + 1][j]);
			j++;
		}
		i++;
	}
}
