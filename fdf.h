/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:49:18 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 08:27:37 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

/*
 ** definitions
 ** --------
*/

# define FDF_H

# define H 1080
# define W 1920
# define MENU_W 250
# define LH 27
# define WH 0xFFFFFF
# define PAD 20
# define DARK_IMG 0x141413
# define LIGHT_IMG 0x757574
# define DARK_MENU 0x101009
# define LIGHT_MENU 0x686867

/*
 ** includes
 ** --------
*/

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/*
 ** structures
 ** ----------
*/

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_fdf
{
	t_point				**map;
	int					width;
	int					height;
	struct		s_params
	{
		void			*mlx_ptr;
		void			*win_ptr;
		void			*img_ptr;
		int				*data;
		unsigned char	camera:1;
		int				scale;
		double			x_angle;
		double			y_angle;
		double			z_angle;
		int				z_alt;
		int				x;
		int				y;
		int				animation;
		int				a_x;
		int				a_y;
		int				a_z;
		int				x_mouse;
		int				y_mouse;
		int				theme:1;
	}					params;
}				t_fdf;

/*
 ** Functions
 ** --------------
*/

int				ft_check_file(int fd, t_fdf *fdf, t_list **alst);
int				lst_to_map(t_fdf *fdf, t_list **alst);
int				ft_hextoi(const char *hex);
void			draw_line(t_fdf *fdf, t_point start, t_point end);
void			draw_map(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
int				mouse_press(int key, int x, int y, t_fdf *fdf);
int				key_press(int keycode, t_fdf *fdf);
void			scale(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
void			project_iso(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
void			center(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
void			kit(t_fdf *fdf);
void			x_rotation(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
void			y_rotation(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
void			z_rotation(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
void			z_altitude(t_fdf *fdf, t_point map[fdf->height][fdf->width]);
int				best_zoom(int height, int width);
void			usage(t_fdf fdf);
void			move(t_fdf fdf, t_point map[fdf.height][fdf.width]);
int				mouse_move(int x, int y, t_fdf *fdf);
int				mouse_release(int button, int x, int y, t_fdf *fdf);
void			make_usage_background(t_fdf fdf, int x, int x_end, int color);
int				animation(t_fdf *fdf);
void			make_usage_background(t_fdf fdf, int x, int x_end, int color);

#endif
