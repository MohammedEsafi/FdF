/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 03:41:42 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 18:06:49 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	create_point(char *str, t_point *point, int x, int y)
{
	char	**split;

	split = ft_strsplit(str, ',');
	point->x = str ? x : 0;
	point->y = str ? y : 0;
	point->z = str ? ft_atoi(split[0]) : 0;
	if (point->z >= 100)
		point->z = 100;
	else if (point->z <= -100)
		point->z = -100;
	point->color = split[1] == 0 ? 0xFF7A71 : ft_hextoi(split[1]);
	if (point->z >= 1 && split[1] == 0)
		point->color = 0xfbf7c3;
	ft_strdel(split);
	ft_strdel(split + 1);
	free(split);
}

void		lstshift(t_list **alst)
{
	unsigned	i;
	t_list		*tmp;

	i = 0;
	while (i < (*alst)->content_size)
	{
		ft_strdel(((char **)(*alst)->content) + i);
		i++;
	}
	free((*alst)->content);
	tmp = *alst;
	*alst = (*alst)->next;
	free(tmp);
}

int			lst_to_map(t_fdf *fdf, t_list **alst)
{
	int		i;
	int		j;

	if ((fdf->map = (t_point **)malloc(sizeof(t_point *) * fdf->height)) == 0)
		return (-5);
	i = fdf->height - 1;
	while (*alst)
	{
		j = 0;
		if (!(fdf->map[i] = (t_point *)malloc(sizeof(t_point) * fdf->width)))
			return (-5);
		while (j < fdf->width)
		{
			create_point(((char **)(*alst)->content)[j], fdf->map[i] + j, j, i);
			j++;
		}
		i--;
		lstshift(alst);
	}
	return (1);
}
