/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:31:22 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/12 16:35:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelat(t_list **alst, int index)
{
	t_list	*tmp;
	t_list	*prv;

	if (alst == NULL || index < 0)
		return (NULL);
	if (index == 0)
	{
		return (ft_lstshift(alst));
	}
	tmp = *alst;
	while (index--)
	{
		if (tmp == NULL)
			return (NULL);
		prv = tmp;
		tmp = tmp->next;
	}
	prv->next = tmp->next;
	return (tmp);
}
