/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_theme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:57:40 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/11 15:57:48 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handler_theme(int key, t_fdf *fdf)
{
	if (key == 37)
	{
		fdf->params.theme = ~fdf->params.theme;
		make_usage_background(*fdf, 0, MENU_W - 1, fdf->params.theme ?
								LIGHT_MENU : DARK_MENU);
		usage(*fdf);
	}
}
