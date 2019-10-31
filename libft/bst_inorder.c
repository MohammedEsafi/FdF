/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_inorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:47:48 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/25 12:35:45 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bst_inorder(t_bst *root)
{
	if (root == NULL)
		return ;
	bst_inorder(root->left);
	ft_putnbr(root->key);
	ft_putendl(0);
	bst_inorder(root->right);
}
