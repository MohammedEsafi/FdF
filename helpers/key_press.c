/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:51:20 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 16:53:16 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int		key_press(int keycode, t_fdf *fdf)
{
	handler_camera(keycode, fdf);
	handler_scale(keycode, fdf);
	handler_x_angle(keycode, fdf);
	handler_y_angle(keycode, fdf);
	handler_z_angle(keycode, fdf);
	handler_z_alt(keycode, fdf);
	handler_2d(keycode, fdf);
	handler_animation_direction(keycode, fdf);
	handler_theme(keycode, fdf);
	handler_animation(keycode, fdf);
	if (keycode == 53)
	{
		ft_free_map(fdf);
		exit(0);
	}
	mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
	kit(fdf);
	return (0);
}
