/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:53:25 by iporsenn          #+#    #+#             */
/*   Updated: 2018/09/30 17:53:27 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

void	init_textures(t_global *g)
{
	g->wall.p_img = mlx_xpm_file_to_image(g->mlx, WALL, &g->wall.x, &g->wall.y);
	g->wall.img_addr = mlx_get_data_addr(g->wall.p_img, &g->wall.bpp, \
												&g->wall.size, &g->wall.endian);
	g->floor.p_img = mlx_xpm_file_to_image(g->mlx, FLOOR, &g->floor.x, \
																&g->floor.y);
	g->floor.img_addr = mlx_get_data_addr(g->floor.p_img, &g->floor.bpp, \
											&g->floor.size, &g->floor.endian);
	g->ceiling.p_img = mlx_xpm_file_to_image(g->mlx, CEILING, \
												&g->ceiling.x, &g->ceiling.y);
	g->floor.img_addr = mlx_get_data_addr(g->ceiling.p_img, &g->ceiling.bpp, \
										&g->ceiling.size, &g->ceiling.endian);
}

void			init_global(t_global *global)
{
	int		i;
	char	*title;

	i = -1;
	title = ft_strjoin("Wolf3d :", global->name);
	global->mlx = mlx_init();
	global->win = mlx_new_window(global->mlx, WIDTH, HEIGHT, title);
	global->p_img = mlx_new_image(global->mlx, WIDTH, HEIGHT);
	global->img_addr = mlx_get_data_addr(global->p_img, &global->bpp, \
												&global->size, &global->endian);
	global->x_init = 0;
	global->y_init = 0;
	global->time = 0;
	global->old_time = 0;
	// global->color = 0xFFFFFF; couleur pour mini_map
	global->key_func[0] = &close_map;
	global->len_key = 1;
	while (++i < THREAD)
		global->thread[i] = 0;
	free(title);
	init_textures(global);
}

char	*load_map(t_global *g)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		ret;

	str = ft_strnew(0);
	if ((ret = get_next_line(g->fd, &line)) < 0)
		error("Error : map file invalid.");
	while ((ret = get_next_line(g->fd, &line)))
	{
		if (ret == -1)
		{
			free(str);
			free(line);
			return (NULL);
		}
		tmp = str;
		str = ft_strjoin(str, line);
		free(line);
		str = ft_strcat(str, "\n");
		free(tmp);
	}
	close(g->fd);
	return (str);
}

void	init_map(t_global *g)
{
	char	**c_map;
	size_t	i;
	char	*str;

	str = load_map(g);
	c_map = ft_strsplit(str, '\n');
	g->map_x = count_word((const char*)c_map[1], ' ');
	if (!(g->map = (int**)malloc(sizeof(int*) * ft_tablen(c_map) + 1)))
		error("Error : map malloc failed.");
	i = 0;
	while (i != ft_tablen(c_map))
	{
		if (!(g->map[i] = ft_splitoa(c_map[i], ' ')))
			error("Error : map conversion failed.");
		i++;
	}
	g->map[i] = NULL;
	i = -1;
	while (c_map[++i])
		free(c_map[i]);
	free(c_map);
	free(str);
	check_start_pos(g);
	init_global(g);
}
