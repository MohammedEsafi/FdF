/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 03:54:39 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/14 23:54:20 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src - dst > 0)
		ft_memcpy(dst, src, len);
	else if (src - dst < 0)
		while (len > 0)
		{
			len--;
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		}
	return (dst);
}
