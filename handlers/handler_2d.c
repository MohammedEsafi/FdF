/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:55:55 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 15:56:04 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_2d(int key, t_fdf *fdf)
{
	if (key == 82 || key == 8)
		fdf->params.x = 0;
	else if (key == 123 || key == 0)
		fdf->params.x -= 8;
	else if (key == 124 || key == 2)
		fdf->params.x += 8;
	if (key == 82 || key == 8)
		fdf->params.y = 0;
	else if (key == 126 || key == 13)
		fdf->params.y -= 8;
	else if (key == 125 || key == 1)
		fdf->params.y += 8;
}
