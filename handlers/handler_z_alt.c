/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_z_alt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:55:31 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 15:55:41 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_z_alt(int key, t_fdf *fdf)
{
	if (key == 82)
		fdf->params.z_alt = 0;
	else if (key == 24 || key == 69)
		fdf->params.z_alt += 1;
	else if (key == 27 || key == 78)
		fdf->params.z_alt -= 1;
}
