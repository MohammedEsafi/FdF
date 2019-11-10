/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:47:48 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 23:02:57 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int			mouse_press(int key, int x, int y, t_fdf *fdf)
{
	if (x >= 48 && x <= 60 && y >= -16 && y <= -4)
	{
		// free before exiting
		exit(0);
	}
	if (key == 4)
	{
		fdf->params.scale += 2;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (key == 5)
	{
		if (fdf->params.scale > 0)
			fdf->params.scale -= 2;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (key == 1 && y >= 0 && y <= H && x >= MENU_W && x <= W)
	{
		fdf->params.x_mouse = x;
		fdf->params.y_mouse = y;
	}
	return (1);
}
