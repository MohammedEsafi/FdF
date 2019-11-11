/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_z_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:02:25 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 16:02:34 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_z_angle(int key, t_fdf *fdf)
{
	if (key == 85 || key == 92)
		fdf->params.z_angle += 0.0628319;
	else if (key == 83 || key == 89)
		fdf->params.z_angle -= 0.0628319;
	else if ((key == 3 || key == 17) && fdf->params.camera == 0)
		fdf->params.z_angle = 0;
	else if (key == 15 && fdf->params.camera == 0)
		fdf->params.z_angle = 1.5708;
	else if (key == 82)
		fdf->params.z_angle = 0;
}
