/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:01:59 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 16:02:02 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_x_angle(int key, t_fdf *fdf)
{
	if (key == 91)
		(fdf->params.x_angle += 0.0628319);
	else if (key == 84)
		fdf->params.x_angle -= 0.0628319;
	else if ((key == 15 || key == 3) && fdf->params.camera == 0)
		fdf->params.x_angle = 1.5708;
	else if (key == 17 && fdf->params.camera == 0)
		fdf->params.x_angle = 0;
	else if (key == 82)
		fdf->params.x_angle = 0;
}
