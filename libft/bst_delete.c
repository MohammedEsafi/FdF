/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:46:23 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/24 17:03:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bst_delete(t_bst *root)
{
	if (root == NULL)
		return ;
	bst_delete(root->left);
	bst_delete(root->right);
	free(root->content);
	free(root);
}
