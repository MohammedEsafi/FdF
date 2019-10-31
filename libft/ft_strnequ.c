/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:29:08 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/04 23:29:54 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t size)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strncmp((char *)s1, (char *)s2, size) == 0);
}
