/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:07:20 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 16:57:18 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialise_fdf(t_fdf *fdf)
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
		fdf->params.x_mouse = 0;
		fdf->params.y_mouse = 0;
		fdf->params.theme = 0;
	}
}

static void	error_handler(t_fdf *fdf, t_list **alst, int status, char **argv)
{
	if (status == -1)
	{
		ft_putstr("No file ");
		ft_putendl(argv[1]);
	}
	if (status == -2)
	{
		ft_free_map(fdf);
		ft_putendl("Found wrong line length. Exiting.");
	}
	if (status == -3)
		ft_putendl("Empty File.");
	if (status == -4)
		ft_putendl("No data found.");
	if (status == -5)
	{
		if (fdf->map != 0)
			ft_free_map(fdf);
		while (*alst)
			lstshift(alst);
		ft_putendl("Unknown Error.");
	}
	if (status < 0)
		exit(1);
}

static int	exit_hook(t_fdf *fdf)
{
	ft_free_map(fdf);
	exit(0);
	return (0);
}

static void	hook(t_fdf *fdf)
{
	mlx_hook(fdf->params.win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->params.win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->params.win_ptr, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->params.win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->params.win_ptr, 17, 0, exit_hook, fdf);
	mlx_loop_hook(fdf->params.mlx_ptr, animation, fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	t_list	*alst;

	initialise_fdf(&fdf);
	if (argc == 2)
	{
		error_handler(&fdf, &alst, (fd = open(argv[1], O_RDONLY)), argv);
		error_handler(&fdf, &alst, ft_check_file(fd, &fdf, &alst), argv);
		close(fd);
		lst_to_map(&fdf, &alst);
		fdf.params.scale = best_zoom(fdf.height, fdf.width);
		fdf.params.mlx_ptr = mlx_init();
		fdf.params.win_ptr = mlx_new_window(fdf.params.mlx_ptr, W, H, argv[1]);
		make_usage_background(fdf, 0, MENU_W - 1, fdf.params.theme ?
			LIGHT_MENU : DARK_MENU);
		usage(fdf);
		kit(&fdf);
		hook(&fdf);
		mlx_loop(fdf.params.mlx_ptr);
	}
	else
		ft_putendl("Usage : ./fdf <filename>");
	return (0);
}
