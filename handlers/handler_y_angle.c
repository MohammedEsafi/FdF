/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_y_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:02:09 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 16:02:19 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_y_angle(int key, t_fdf *fdf)
{
	if (key == 88)
		fdf->params.y_angle += 0.0628319;
	else if (key == 86)
		fdf->params.y_angle -= 0.0628319;
	else if ((key == 15 || key == 3 || key == 17) && fdf->params.camera == 0)
		fdf->params.y_angle = 0;
	else if (key == 82)
		fdf->params.y_angle = 0;
}
