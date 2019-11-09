/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:39:06 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 10:03:54 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	move(t_fdf fdf, t_point map[fdf.height][fdf.width])
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf.height)
	{
		j = 0;
		while (j < fdf.width)
		{
			map[i][j].x += fdf.params.x;
			map[i][j].y += fdf.params.y;
			j++;
		}
		i++;
	}
}
