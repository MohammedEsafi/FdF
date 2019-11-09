/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:07:04 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 10:05:51 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// static void	make_image_background(t_fdf *fdf, int x, int x_end, int color)
// {
// 	int		y;

// 	while (x <= x_end)
// 	{
// 		y = 0;
// 		while (y <= H)
// 		{
// 			if (y * (W - MENU_W) + x >= 0 && y * (W - MENU_W) + x <= ((H - 1) * (W - MENU_W) + ((W - MENU_W) - 1)))
// 				fdf->params.data[y * (W - MENU_W) + x] = color;
// 			y++;
// 		}
// 		x++;
// 	}
// }

static void	make_image_background(t_fdf *fdf, int color)
{
	int		i;

	i = (H - 1) * (W - MENU_W) + ((W - MENU_W) - 1);
	while (i >= 0)
	{
		fdf->params.data[i--] = color;
	}
}

void		kit(t_fdf *fdf)
{
	int			i;
	t_point		map[fdf->height][fdf->width];
	int bits_per_pixel;
	int size_line;
	int endian;

	i = -1;
	while (++i < fdf->height)
		ft_memcpy(map[i], fdf->map[i], (sizeof(t_point) * fdf->width));
	fdf->params.img_ptr = mlx_new_image(fdf->params.mlx_ptr, W - MENU_W, H);
	fdf->params.data = (int *)mlx_get_data_addr(fdf->params.img_ptr, &bits_per_pixel, &size_line, &endian);
	z_altitude(fdf, map);
	scale(fdf, map);
	x_rotation(fdf, map);
	y_rotation(fdf, map);
	z_rotation(fdf, map);
	if (fdf->params.camera)
		project_iso(fdf, map);
	center(fdf, map);
	if (map[0][0].x + fdf->params.x != map[0][0].x || map[0][0].y + fdf->params.y != map[0][0].y)
		move(*fdf, map);
	make_image_background(fdf, 0x141414);
	draw_map(fdf, map);
	mlx_put_image_to_window(fdf->params.mlx_ptr, fdf->params.win_ptr, fdf->params.img_ptr, MENU_W, 0);
}
