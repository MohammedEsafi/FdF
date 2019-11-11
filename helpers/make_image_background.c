/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:56:06 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 11:56:07 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	make_image_background(t_fdf *fdf, int color)
{
	int		i;

	i = (H - 1) * (W - MENU_W) + ((W - MENU_W) - 1);
	while (i >= 0)
	{
		fdf->params.data[i--] = color;
	}
}
