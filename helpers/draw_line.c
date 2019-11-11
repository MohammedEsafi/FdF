/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 00:48:21 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 19:13:26 by tbareich         ###   ########.fr       */
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

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		get_color(t_point current, t_point start, t_point end)
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

void			init_d(t_draw *d, t_point start, t_point end)
{
	d->delta_x = abs(end.x - start.x);
	d->step_x = start.x < end.x ? 1 : -1;
	d->delta_y = abs(end.y - start.y);
	d->step_y = start.y < end.y ? 1 : -1;
	d->slope_error = (d->delta_x > d->delta_y ? d->delta_x : -d->delta_y) / 2;
}

void			draw_line(t_fdf *fdf, t_point start, t_point end)
{
	t_draw	d;
	t_point	index;

	init_d(&d, start, end);
	index = start;
	while (1)
	{
		index.color = get_color(index, start, end);
		if (index.x < (W - MENU_W) && index.x >= 0 &&
				index.y < H && index.y >= 0)
			fdf->params.data[index.y * (W - MENU_W) + index.x] = index.color;
		if (index.x == end.x && index.y == end.y)
			return ;
		d.tmp = d.slope_error;
		if (d.tmp > -d.delta_x)
		{
			d.slope_error -= d.delta_y;
			index.x += d.step_x;
		}
		if (d.tmp < d.delta_y)
		{
			d.slope_error += d.delta_x;
			index.y += d.step_y;
		}
	}
}
