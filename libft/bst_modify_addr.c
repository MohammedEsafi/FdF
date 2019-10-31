/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:46:51 by tbareich          #+#    #+#             */
/*   Updated: 2019/05/07 14:55:20 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bst_modify_addr(t_bst *node, void *content, size_t content_size)
{
	if (node == NULL)
		return (-1);
	if (node->content != NULL)
	{
		free(node->content);
		node->content = NULL;
	}
	if (content == NULL || content_size == 0)
	{
		node->content = NULL;
		node->content_size = 0;
		return (0);
	}
	node->content = malloc(content_size);
	if (node->content)
	{
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	else
	{
		node->content_size = 0;
		return (-1);
	}
	return (0);
}
