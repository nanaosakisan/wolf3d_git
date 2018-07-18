/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:40:51 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/05 17:40:53 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

static void		init_img(t_img *img)
{
	img->p_mlx = NULL;
	img->p_win = NULL;
	img->p_img = NULL;
	img->img_addr = NULL;
	img->bpp = 0;
	img->size = 0;
	img->endian = 0;
}

static void		init_map(t_map *map)
{
	map->p_img = NULL;
	map->img_addr = NULL;
	map->bpp = 0;
	map->size = 0;
	map->endian = 0;
}

void			init_global(t_global *global)
{
	int i;

	i = -1;
	global->wall = NULL;
	global->width = 0;
	global->height = 0;
	global->x_init = 0;
	global->y_init = 0;
	global->color = 0xFFFFFF;
	global->key_func[0] = &close_map;
	global->len_key = 1;
	while (++i < THREAD)
		global->thread[i] = 0;
	init_img(&global->img);
	init_map(&global->map);
}
