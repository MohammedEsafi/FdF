/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 00:48:21 by tbareich          #+#    #+#             */
/*   Updated: 2019/10/28 14:04:15 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(void *mlx_ptr, void *win_ptr, t_point start, t_point end)
{
	int		dx;
	int		dy;
	int		delta;
	int		x;
	int		y;

	dx = end.x - start.x;
	dy = end.y - start.y;
	delta = dy * 2 - dx;
	x = start.x;
	y = start.y;
	while (x <= end.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 255);
		if (delta > 0)
		{
			y++;
			delta -= 2 * dx;
		}
		delta += 2 * dy;
		x++;
	}
}
