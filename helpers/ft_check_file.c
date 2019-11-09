/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:27:07 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/09 12:45:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_elm(char **tab)
{
	int		count;

	count = 0;
	while (*tab)
	{
		tab++;
		count++;
	}
	return (count);
}

int			ft_check_file(int fd, t_fdf *fdf, t_list **alst)
{
	char	*line;
	char	**splited_line;
	t_list	*lst_elm;
	int		first_read;

	first_read = 1;
	*alst = 0;
	while (get_next_line(fd, &line) == 1)
	{
		first_read = 0;
		if ((splited_line = ft_strsplit(line, ' ')))
		{
			ft_strdel(&line);
			lst_elm = (t_list*)malloc(sizeof(t_list));
			lst_elm->content = splited_line;
			lst_elm->content_size = count_elm(splited_line);
			ft_lstadd(alst, lst_elm);
			if (fdf->height == 0)
				fdf->width = lst_elm->content_size;
			else if (fdf->width > (int)lst_elm->content_size)
				return (-2);
		}
		fdf->height++;
	}
	return (first_read);
}
