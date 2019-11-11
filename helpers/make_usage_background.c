/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_usage_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:01:38 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 09:01:40 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	make_usage_background(t_fdf fdf, int x, int x_end, int color)
{
	int		y;

	while (x <= x_end)
	{
		y = 0;
		while (y <= H)
		{
			mlx_pixel_put(fdf.params.mlx_ptr, fdf.params.win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}
