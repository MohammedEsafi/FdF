/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:51:20 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 12:37:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 91)
	{
		fdf->params.x_angle += 0.10472;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 84)
	{
		fdf->params.x_angle -= 0.10472;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 88)
	{
		fdf->params.y_angle += 0.10472;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 86)
	{
		fdf->params.y_angle -= 0.10472;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 85)
	{
		fdf->params.z_angle += 0.10472;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 83)
	{
		fdf->params.z_angle -= 0.10472;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 3 && fdf->params.camera == 0)
	{
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.x_angle = -1.5708;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 15 && fdf->params.camera == 0)
	{
		fdf->params.y_angle = 1.5708;
		fdf->params.z_angle = 0;
		fdf->params.x_angle = -1.5708;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 17 && fdf->params.camera == 0)
	{
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.x_angle = 0;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 34)
	{
		fdf->params.camera = 1;
		fdf->params.x_angle = 0;
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 31)
	{
		fdf->params.camera = 0;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 82)
	{
		fdf->params.x_angle = 0;
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.x = 0;
		fdf->params.y = 0;
		fdf->params.z_alt = 0;
		fdf->params.camera = 1;
		fdf->params.scale = best_zoom(fdf->height, fdf->width);
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 24 || keycode == 69)
	{
		fdf->params.z_alt += 3;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 27 || keycode == 78)
	{
		fdf->params.z_alt -= 3;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 126)
	{
		fdf->params.y -= 8;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 125)
	{
		fdf->params.y += 8;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 123)
	{
		fdf->params.x -= 8;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 124)
	{
		fdf->params.x += 8;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	if (keycode == 53)
	{
		// free map && t_lst
		exit(0);
	}
	return (0);
}
