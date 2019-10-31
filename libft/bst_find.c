/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:34:31 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/29 23:07:28 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*bst_find(t_bst *root, int key)
{
	if (root == NULL || root->key == key)
		return (root);
	if (key > root->key)
		return (bst_find(root->right, key));
	return (bst_find(root->left, key));
}
