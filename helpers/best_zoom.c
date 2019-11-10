/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:25:48 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/10 06:31:15 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		best_zoom(int height, int width)
{
	int		h;
	int		w;

	h = (float)H / 3;
	w = (float)W / 3;
	return ((h / height) < (w / width) ? (h / height) : (w / width));
}
