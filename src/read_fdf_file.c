/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:42:53 by tbareich          #+#    #+#             */
/*   Updated: 2019/10/31 13:51:49 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		ft_clean_splitedstr(char **splitedstr)
{
	while (*splitedstr)
	{
		ft_strdel(splitedstr);
		splitedstr++;
	}
}

static int		ft_strsplite_len(char **splitedstr)
{
	int		i;

	i = 0;
	while (splitedstr[i])
		i++;
	return (i);
}

int		fill_matrix(char *str, t_matrix *matrix)
{
	char	**lines;
	char	**single_line;
	char	**color_z;
	int		i;
	int		j;

	i = 0;
	lines = ft_strsplit(str, '\n');
	matrix->rows = ft_strsplite_len(lines);
	matrix->matrix = (t_point **)malloc(sizeof(t_point *) * matrix->rows);
	while (lines[i])
	{
		j = 0;
		single_line = ft_strsplit(lines[i], ' ');
		matrix->cols = ft_strsplite_len(single_line);
		matrix->matrix[i] = (t_point *)malloc(sizeof(t_point) * matrix->cols);
		while (single_line[j])
		{
			color_z = ft_strsplit(single_line[j], ',');
			matrix->matrix[i][j].x = j;
			matrix->matrix[i][j].y = i;
			matrix->matrix[i][j].z = ft_atoi(color_z[0]);
			matrix->matrix[i][j].color = color_z[1] ? ft_hextoi(color_z[1] + 2)
											: 0xffffff;
			j++;
			ft_clean_splitedstr(color_z);
		}
		ft_clean_splitedstr(single_line);
		i++;
	}
	ft_clean_splitedstr(lines);
	return (1);
}

char			*read_fdf_file(int fd)
{
	int		readed;
	char	*line;
	char	*str;
	char	*tmp;

	readed = 0;
	str = ft_strnew(0);
	while ((readed = get_next_line(fd, &line)))
	{
		tmp = str;
		str = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		if (str == 0)
			return (0);
		tmp = str;
		str = ft_strjoin(str, line);
		ft_strdel(&tmp);
		if (str == 0)
			return (0);
	}
	return (str);
}
