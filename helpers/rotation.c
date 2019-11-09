/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 08:55:51 by ael-makk          #+#    #+#             */
/*   Updated: 2019/11/09 10:01:45 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	x_rotation(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int i;
	int j;
	int y;
	int z;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			y = map[i][j].y;
			z = map[i][j].z;
			map[i][j].y = y * cos(fdf->params.x_angle) + z *
							sin(fdf->params.x_angle);
			map[i][j].z = -y * sin(fdf->params.x_angle) + z *
							cos(fdf->params.x_angle);
			j++;
		}
		i++;
	}
}

void	y_rotation(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int i;
	int j;
	int x;
	int z;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			x = map[i][j].x;
			z = map[i][j].z;
			map[i][j].x = x * cos(fdf->params.y_angle) + z *
							sin(fdf->params.y_angle);
			map[i][j].z = -x * sin(fdf->params.y_angle) + z *
							cos(fdf->params.y_angle);
			j++;
		}
		i++;
	}
}

void	z_rotation(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int i;
	int j;
	int y;
	int x;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			y = map[i][j].y;
			x = map[i][j].x;
			map[i][j].x = x * cos(fdf->params.z_angle) - y *
							sin(fdf->params.z_angle);
			map[i][j].y = x * sin(fdf->params.z_angle) + y *
							cos(fdf->params.z_angle);
			j++;
		}
		i++;
	}
}
