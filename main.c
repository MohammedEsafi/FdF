/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:23:37 by tbareich          #+#    #+#             */
/*   Updated: 2019/10/31 13:49:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		main(void)
{
	// void		*mlx_ptr;
	// void		*win_ptr;
	t_matrix	matrix;
	int			fd;

	fd = open("42.fdf", O_RDONLY);
	fdf(fd, &matrix);
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1280, 720, "fdf");
	// mlx_loop(mlx_ptr);
	return (0);
}
