/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:07:04 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 15:40:57 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	copy_map(t_fdf *fdf, t_point map[fdf->height][fdf->width])
{
	int		i;

	i = -1;
	while (++i < fdf->height)
		ft_memcpy(map[i], fdf->map[i], (sizeof(t_point) * fdf->width));
}

void		kit(t_fdf *fdf)
{
	t_point		map[fdf->height][fdf->width];
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	copy_map(fdf, map);
	fdf->params.img_ptr = mlx_new_image(fdf->params.mlx_ptr, W - MENU_W, H);
	fdf->params.data = (int *)mlx_get_data_addr(fdf->params.img_ptr,
								&bits_per_pixel, &size_line, &endian);
	z_altitude(fdf, map);
	scale(fdf, map);
	z_rotation(fdf, map);
	y_rotation(fdf, map);
	x_rotation(fdf, map);
	if (fdf->params.camera)
		project_iso(fdf, map);
	center(fdf, map);
	if (map[0][0].x + fdf->params.x != map[0][0].x ||
		map[0][0].y + fdf->params.y != map[0][0].y)
		move(*fdf, map);
	make_image_background(fdf, fdf->params.theme ? LIGHT_IMG : DARK_IMG);
	draw_map(fdf, map);
	mlx_put_image_to_window(fdf->params.mlx_ptr, fdf->params.win_ptr,
								fdf->params.img_ptr, MENU_W, 0);
}
