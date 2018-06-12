/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:25:20 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/05 17:25:22 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

static void		*malloc_map(t_global *global, int cpt, int len)
{
	int i;

	if (!(global->wall = (int**)ft_memalloc(sizeof(int*) * cpt)))
		return (NULL);
	i = -1;
	while (++i < cpt)
	{
		if (!(global->wall[i] = (int*)ft_memalloc(sizeof(int) * len)))
			return (NULL);
	}
	return (NULL);
}

static void		fill_tab(t_global *global, char **array, int y, int len_array)
{
	int x;

	x = -1;
	while (++x < len_array)
		global->wall[y][x] = ft_atoi(array[x]);
}

void			parsing(t_global *global, char *line, int cpt)
{
	char		**array;
	int			len_array;
	static int	y = -1;

	len_array = count_word(line, ' ');
	y++;
	array = ft_strsplit(line, ' ');
	if (!global->wall)
		malloc_map(global, cpt, len_array);
	fill_tab(global, array, y, len_array);
	global->width = cpt;
	global->height = len_array;
	free_array(array, len_array);
}

int			lauchn_parse(t_global *global, int fd, char **av)
{
	int		ret;
	int		cpt;
	char	*line;

	ret = 0;
	cpt = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// if ((check_map(&line, cpt)) != 1)
		// 	return (0);
		cpt++;
		ft_strdel(&line);
	}
	if ((close(fd)) == -1)
		error("closed() failed");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("open() failed");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parsing(global, line, cpt);
		ft_strdel(&line);
	}
	return (1);
}
