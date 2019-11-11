/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:50:09 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 16:58:42 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_map(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->height)
	{
		if (fdf->map[i] == 0)
			break ;
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
}
