/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:08:16 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/09 10:08:26 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void    usage(t_fdf fdf)
{
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 1 * LINE_HEIGHT, 0xffffff, "     How to Use");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 3 * LINE_HEIGHT, 0xffffff, "Zoom: Scroll");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 4 * LINE_HEIGHT, 0xffffff, "Move: Arrows");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 5 * LINE_HEIGHT, 0xffffff, "Rotate:");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 6 * LINE_HEIGHT, 0xffffff, "  X-Axis: 2/8");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 7 * LINE_HEIGHT, 0xffffff, "  Y-Axis: 4/6");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 8 * LINE_HEIGHT, 0xffffff, "  Z-Axis: 1/3");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 9 * LINE_HEIGHT, 0xffffff, "Projection:");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 10 * LINE_HEIGHT, 0xffffff, "  ISO: I Key");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 11 * LINE_HEIGHT, 0xffffff, "  Orthographic: O Key");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 12 * LINE_HEIGHT, 0xffffff, "    Top: T Key");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 13 * LINE_HEIGHT, 0xffffff, "    Rigth: R Key");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 14 * LINE_HEIGHT, 0xffffff, "    Front: F Key");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 15 * LINE_HEIGHT, 0xffffff, "Altitude: +(=)/-");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 17 * LINE_HEIGHT, 0xffffff, "Initialization: 0 Key");
    mlx_string_put(fdf.params.mlx_ptr, fdf.params.win_ptr, PADDING, 18 * LINE_HEIGHT, 0xffffff, "Exit: ESC Key");
}
