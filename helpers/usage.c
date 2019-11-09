/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:08:16 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 15:38:04 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	usage(t_fdf fdf)
{
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = fdf.params.mlx_ptr;
	win_ptr = fdf.params.win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, PAD, 1 * LH, WH, "     How to Use");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 3 * LH, WH, "Zoom: Scroll");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 4 * LH, WH, "Move: Arrows(W/A/S/D)");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 5 * LH, WH, "Rotate:");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 6 * LH, WH, "  X-Axis: 2/8");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 7 * LH, WH, "  Y-Axis: 4/6");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 8 * LH, WH, "  Z-Axis: 1/3");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 9 * LH, WH, "Projection:");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 10 * LH, WH, "  ISO: I Key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 11 * LH, WH, "  Orthographic: O Key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 12 * LH, WH, "    Top: T Key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 13 * LH, WH, "    Rigth: R Key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 14 * LH, WH, "    Front: F Key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 15 * LH, WH, "Altitude: +(=)/-");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 16 * LH, WH, "Animation: Space key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 17 * LH, WH, "Center: C key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 19 * LH, WH, "Initialization: 0 Key");
	mlx_string_put(mlx_ptr, win_ptr, PAD, 20 * LH, WH, "Exit: ESC Key");
}
