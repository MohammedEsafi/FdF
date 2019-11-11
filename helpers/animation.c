/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:55:17 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 08:55:20 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	animation(t_fdf *fdf)
{
	if (fdf->params.animation)
	{
		fdf->params.x_angle += 0.0174533 * fdf->params.a_x;
		fdf->params.y_angle += 0.0174533 * fdf->params.a_y;
		fdf->params.z_angle += 0.0174533 * fdf->params.a_z;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	return (0);
}
