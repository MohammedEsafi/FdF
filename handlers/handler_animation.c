/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:57:56 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 15:58:05 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_animation(int key, t_fdf *fdf)
{
	if (key == 49)
	{
		fdf->params.animation = ~fdf->params.animation;
		if (!fdf->params.a_x && !fdf->params.a_y && !fdf->params.a_z)
			fdf->params.a_z = 1;
	}
}
