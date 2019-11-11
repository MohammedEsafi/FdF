/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:27:07 by tbareich          #+#    #+#             */
/*   Updated: 2019/11/11 18:57:03 by tbareich         ###   ########.fr       */
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

	*alst = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(splited_line = ft_strsplit(line, ' ')))
			return (-3);
		ft_strdel(&line);
		if (splited_line[0] == 0)
		{
			free(splited_line);
			return (fdf->width == 0 ? -2 : -3);
		}
		if ((lst_elm = (t_list*)malloc(sizeof(t_list))) == 0)
			return (-5);
		lst_elm->content = splited_line;
		lst_elm->content_size = count_elm(splited_line);
		ft_lstadd(alst, lst_elm);
		fdf->height++ == 0 && (fdf->width = lst_elm->content_size);
		if (fdf->width > (int)lst_elm->content_size)
			return (-2);
	}
	return (fdf->height != 0 ? 0 : -4);
}
