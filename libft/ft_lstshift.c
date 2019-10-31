/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 04:31:23 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/09 04:54:36 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstshift(t_list **alst)
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL)
		return (NULL);
	tmp = *alst;
	*alst = (*alst)->next;
	return (tmp);
}
