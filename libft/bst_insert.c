/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:21:38 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/25 10:41:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*bst_insert(t_bst *root, t_bst *node)
{
	if (root == NULL)
		return (node);
	if (node->key < root->key)
		root->left = bst_insert(root->left, node);
	if (node->key > root->key)
		root->right = bst_insert(root->right, node);
	return (root);
}
