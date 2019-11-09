/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:25:48 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/08 17:26:00 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		best_zoom(int height, int width)
{
	int		h;
	int		w;

	h = (float)H / 5;
	w = (float)W / 5;
	return ((h / height) < (w / width) ? (h / height) : (w / width));
}
