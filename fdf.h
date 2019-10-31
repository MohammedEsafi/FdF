/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:17:29 by tbareich          #+#    #+#             */
/*   Updated: 2019/10/30 16:04:09 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}				t_point;

typedef struct	s_matrix
{
	t_point		**matrix;
	int			rows;
	int			cols;
}				t_matrix;

void			draw_line(void *mlx_ptr, void *win_ptr, t_point start,
							t_point end);
char			*read_fdf_file(int fd);
int				ft_hextoi(const char *hex);
void			fdf(int fd, t_matrix *matrix);
int				fill_matrix(char *str, t_matrix *matrix);

#endif
