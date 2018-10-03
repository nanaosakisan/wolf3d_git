/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:53:25 by iporsenn          #+#    #+#             */
/*   Updated: 2018/10/02 16:33:00 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

static void		init_textures(t_global *g)
{
	if(!(g->wall.p_img = mlx_xpm_file_to_image(g->mlx, WALL, &g->wall.x, \
			&g->wall.y)))
		error("Error : no texture found for wall.");
	g->wall.img_addr = mlx_get_data_addr(g->wall.p_img, &g->wall.bpp, \
			&g->wall.size, &g->wall.endian);
	if (!(g->floor.p_img = mlx_xpm_file_to_image(g->mlx, FLOOR, &g->floor.x, \
			&g->floor.y)))
		error("Error : no texture found for floor.");
	g->floor.img_addr = mlx_get_data_addr(g->floor.p_img, &g->floor.bpp, \
			&g->floor.size, &g->floor.endian);
	if (!(g->ceiling.p_img = mlx_xpm_file_to_image(g->mlx, CEILING, \
			&g->ceiling.x, &g->ceiling.y)))
		error("Error : no texture found for ceiling.");
	g->floor.img_addr = mlx_get_data_addr(g->ceiling.p_img, &g->ceiling.bpp, \
			&g->ceiling.size, &g->ceiling.endian);
}

static void init_ray(t_rayon *ray)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->perp_walldist = 0;
}

void		init_global(t_global *global)
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
	global->time = 0;
	global->old_time = 0;
	global->color = 0xFFFFFF;
	global->key_func[0] = &close_map;
	global->key_func[1] = &get_dir;
	global->key_func[2] = &get_pos;
	global->len_key = 3;
	while (++i < THREAD)
		global->thread[i] = 0;
	free(title);
	init_textures(global);
	init_ray(&global->ray);
}

char	**load_map(t_global *g)
{
	char	**dest;
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	if ((ret = get_next_line(g->fd, &line)) < 0)
		error("Error : map file invalid.");
	ft_strdel(&line);
	i = 0;
	if (!(dest = (char**)malloc(sizeof(char*) * g->max_y + 1)))
		error("Error : malloc failed.");
	while ((ret = get_next_line(g->fd, &line)))
	{
		if (ret == -1)
			error("Nope.");
		dest[i] = ft_strdup(line);
		i++;
	}
	dest[i] = NULL;
	close(g->fd);
	return (dest);
}

void	init_map(t_global *g)
{

	char	**c_map;
	size_t	i;
	size_t	len_tab;

	c_map = load_map(g);
	g->max_x = count_word((const char*)c_map[0], ' ');
	if (!(g->map = (int**)malloc(sizeof(int*) * ft_tablen(c_map) + 1)))
		error("0");
	len_tab = ft_tablen(c_map);
	i = 0;
	while (i != len_tab)
	{
		if (!(g->map[i] = ft_splitoa(c_map[i], ' ')))
			error("0");
		i++;
	}
	g->map[i] = NULL;
	i = -1;
	while (c_map[++i])
		free(c_map[i]);
	free(c_map);
}
