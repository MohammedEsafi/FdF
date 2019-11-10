/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:51:20 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/10 06:58:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int			key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 91)
	{
		fdf->params.x_angle += 0.0628319;
		fdf->params.a_x = 1;
		fdf->params.a_y = 0;
		fdf->params.a_z = 0;
	}
	if (keycode == 84)
	{
		fdf->params.a_x = -1;
		fdf->params.a_y = 0;
		fdf->params.a_z = 0;
		fdf->params.x_angle -= 0.0628319;
	}
	if (keycode == 88)
	{
		fdf->params.a_x = 0;
		fdf->params.a_y = 1;
		fdf->params.a_z = 0;
		fdf->params.y_angle += 0.0628319;
	}
	if (keycode == 86)
	{
		fdf->params.a_x = 0;
		fdf->params.a_y = -1;
		fdf->params.a_z = 0;
		fdf->params.y_angle -= 0.0628319;
	}
	if (keycode == 85 || keycode == 92)
	{
		fdf->params.a_x = 0;
		fdf->params.a_y = 0;
		fdf->params.a_z = 1;
		fdf->params.z_angle += 0.0628319;
	}
	if (keycode == 83 || keycode == 89)
	{
		fdf->params.a_x = 0;
		fdf->params.a_y = 0;
		fdf->params.a_z = -1;
		fdf->params.z_angle -= 0.0628319;
	}
	if (keycode == 3 && fdf->params.camera == 0)
	{
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.x_angle = 1.5708;
	}
	if (keycode == 15 && fdf->params.camera == 0)
	{
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 1.5708;
		fdf->params.x_angle = 1.5708;
	}
	if (keycode == 17 && fdf->params.camera == 0)
	{
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.x_angle = 0;
	}
	if (keycode == 34)
	{
		fdf->params.camera = 1;
	}
	if (keycode == 31)
	{
		fdf->params.camera = 0;
	}
	if (keycode == 82)
	{
		fdf->params.x_angle = 0;
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.x = 0;
		fdf->params.y = 0;
		fdf->params.z_alt = 0;
		fdf->params.animation = 0;
		fdf->params.camera = 1;
		fdf->params.scale = best_zoom(fdf->height, fdf->width);
	}
	if (keycode == 24 || keycode == 69)
	{
		fdf->params.z_alt += 1;
	}
	if (keycode == 27 || keycode == 78)
	{
		fdf->params.z_alt -= 1;
	}
	if (keycode == 126 || keycode == 13)
	{
		fdf->params.y -= 8;
	}
	if (keycode == 125 || keycode == 1)
	{
		fdf->params.y += 8;
	}
	if (keycode == 123  || keycode == 0)
	{
		fdf->params.x -= 8;
	}
	if (keycode == 124  || keycode == 2)
	{
		fdf->params.x += 8;
	}
	if (keycode == 8)
	{
		fdf->params.x = 0;
		fdf->params.y = 0;
	}
	if (keycode == 37)
	{
		fdf->params.theme = ~fdf->params.theme;
		make_usage_background(*fdf, 0, MENU_W - 1, fdf->params.theme ?
					LIGHT_MENU : DARK_MENU);
		usage(*fdf);
	}
	if (keycode == 49)
	{
		fdf->params.animation = ~fdf->params.animation;
		if (!fdf->params.a_x && !fdf->params.a_y && !fdf->params.a_z)
		{
			fdf->params.a_z = 1;
		}
	}
	if (keycode == 53)
	{
		// free map && t_lst
		exit(0);
	}
	mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
	kit(fdf);
	return (0);
}
