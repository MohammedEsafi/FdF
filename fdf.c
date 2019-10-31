/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:24:06 by tbareich          #+#    #+#             */
/*   Updated: 2019/10/31 13:55:47 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_clean_matrix(t_matrix *matrix)
{
	int		i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->matrix[i]);
		matrix->matrix[i] = 0;
		i++;
	}
}

void		print_matrix(t_matrix matrix)
{
	int		i;
	int		j;

	j = 0;
	ft_printf("rows : %d\ncols : %d\n", matrix.rows, matrix.cols);
	ft_printf("%s\n", "===============================================");
	while (j < matrix.rows)
	{
		i = 0;
		while (i < matrix.cols)
		{
			ft_printf("{red}x: %-6d{green}y:%-6d {blue}z:%-6d{magenta}color : \
%d{eoc}\n", matrix.matrix[j][i].x,
						matrix.matrix[j][i].y, matrix.matrix[j][i].z,
						matrix.matrix[j][i].color);
			i++;
		}
		j++;
		ft_printf("%s\n", "===============================================");
	}
}

void		fdf(int fd, t_matrix *matrix)
{
	char	*str;

	str = read_fdf_file(fd);
	close(fd);
	if (str == 0)
		return ;
	ft_printf("{green}%s{eoc}\n", str);
	fill_matrix(str, matrix);
	print_matrix(*matrix);
	ft_clean_matrix(matrix);
}
