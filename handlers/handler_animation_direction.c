/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_animation_direction.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:57:20 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 15:57:32 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_animation_direction(int key, t_fdf *fdf)
{
	if (key == 91)
		fdf->params.a_x = 1;
	else if (key == 84)
		fdf->params.a_x = -1;
	else if (key == 83 || key == 89 || key == 88 ||
			key == 86 || key == 85 || key == 92)
		fdf->params.a_x = 0;
	if (key == 88)
		fdf->params.a_y = 1;
	else if (key == 86)
		fdf->params.a_y = -1;
	else if (key == 89 || key == 91 || key == 84 ||
			key == 83 || key == 85 || key == 92)
		fdf->params.a_y = 0;
	if (key == 85 || key == 92)
		fdf->params.a_z = 1;
	else if (key == 83 || key == 89)
		fdf->params.a_z = -1;
	else if (key == 84 || key == 91 || key == 88 || key == 86)
		fdf->params.a_z = 0;
}
