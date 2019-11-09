/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:07:20 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 23:03:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	make_usage_background(t_fdf fdf, int x, int x_end, int color)
{
	int		y;

	while (x <= x_end)
	{
		y = 0;
		while (y <= H)
		{
			mlx_pixel_put(fdf.params.mlx_ptr, fdf.params.win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

static void	initialise_map(t_fdf *fdf)
{
	if (fdf)
	{
		fdf->map = 0;
		fdf->width = 0;
		fdf->height = 0;
		fdf->params.camera = 1;
		fdf->params.x_angle = 0;
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
		fdf->params.z_alt = 0;
		fdf->params.x = 0;
		fdf->params.y = 0;
		fdf->params.animation = 0;
		fdf->params.x_angle = 0;
		fdf->params.y_angle = 0;
		fdf->params.z_angle = 0;
	}
}

static int	animation(t_fdf *fdf)
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

static void	error_handler(int status, char **argv)
{
	if (status == -1)
	{
		ft_putstr("No file ");
		ft_putendl(argv[1]);
		exit(1);
	}
	if (status == -2)
	{
		ft_putendl("Found wrong line length. Exiting.");
		exit(1);
	}
	else if (status == 1)
	{
		ft_putendl("No data found.");
		exit(1);
	}
}

// static int	mouse_release(int button, int x, int y, t_fdf *fdf)
// {
// 	(void)button;
// 	// if (button == 1)
// 	// {
// 		fdf->params.x -= fdf->params.x_mouse - x;
// 		fdf->params.y -= fdf->params.y_mouse - y;
// 	// }
// 	fdf->params.x_mouse = 0;
// 	fdf->params.y_mouse = 0;
// 	mlx_destroy_image(fdf->params.mlx_ptr, fdf->params.img_ptr);
// 	kit(fdf);
// 	return (0);
// }

int			main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	t_list	*alst;

	initialise_map(&fdf);
	if (argc == 2)
	{
		error_handler((fd = open(argv[1], O_RDONLY)), argv);
		error_handler(ft_check_file(fd, &fdf, &alst), argv);
		close(fd);
		lst_to_map(&fdf, &alst);
		fdf.params.scale = best_zoom(fdf.height, fdf.width);
		fdf.params.mlx_ptr = mlx_init();
		fdf.params.win_ptr = mlx_new_window(fdf.params.mlx_ptr, W, H, argv[1]);
		make_usage_background(fdf, 0, MENU_W - 1, 0x121212);
		usage(fdf);
		kit(&fdf);
		mlx_hook(fdf.params.win_ptr, 4, 0, mouse_press, &fdf);
		mlx_hook(fdf.params.win_ptr, 2, 0, key_press, &fdf);
		// mlx_hook(fdf.params.win_ptr, 5, 0, mouse_release, &fdf);
		mlx_loop_hook(fdf.params.mlx_ptr, animation, &fdf);
		mlx_loop(fdf.params.mlx_ptr);
	}
	else
		ft_putendl("Usage : ./fdf <filename>");
	return (0);
}
