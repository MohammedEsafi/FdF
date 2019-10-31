/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:50:49 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/22 22:16:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;
	size_t	m;

	p = ft_memchr(src, c, n);
	m = p ? p - src + 1 : n;
	ft_memcpy(dst, src, m);
	return (!p ? (NULL) : (dst + m));
}
