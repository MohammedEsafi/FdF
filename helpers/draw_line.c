/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 00:48:21 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 09:52:19 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int	get_color(t_point current, t_point start, t_point end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	int		delta;

	delta = (end.x - current.x) - (end.y - current.y);
	if (current.color == end.color)
		return (current.color);
	if (delta > 0)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	int		dx;
	int		dy;
	int		err;
	int		sx;
	int		sy;
	int		e2;
	t_point	current;

	dx = abs(end.x - start.x);
	sx = start.x < end.x ? 1 : -1;
	dy = abs(end.y - start.y);
	sy = start.y < end.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	current = start;
	while (1)
	{
		(void)fdf;
		current.color = get_color(current, start, end);
		if (current.x < (W - MENU_W) && current.x >= 0 && current.y < H && current.y >= 0)
			fdf->params.data[current.y * (W - MENU_W) + current.x] = current.color;
		if (current.x == end.x && current.y == end.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			current.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			current.y += sy;
		}
	}
}
