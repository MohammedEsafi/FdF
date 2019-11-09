/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:49:44 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 23:49:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->params.x_mouse != 0 || fdf->params.y_mouse != 0)
	{
		fdf->params.x -= fdf->params.x_mouse - x;
		fdf->params.y -= fdf->params.y_mouse - y;
		fdf->params.x_mouse = x;
		fdf->params.y_mouse = y;
		mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
		kit(fdf);
	}
	return (0);
}
