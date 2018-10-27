/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:52:01 by iporsenn          #+#    #+#             */
/*   Updated: 2018/10/27 15:46:11 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

int		change_tex(t_global *g, int key)
{
	if (!(T))
		return (0);
	if (g->bonus_tex == 0)
		g->bonus_tex = 1;
	else
		g->bonus_tex = 0;
	start_wolf(g);
	launch_mini_map(g);
	return (1);
}

int		get_dir(t_global *g, int key)
{
	long double tmp_dir;
	long double tmp_plane;

	if (!(LEFT) && !(RIGHT))
		return (0);
	tmp_dir = g->player.dir_x;
	tmp_plane = g->player.plane_x;
	g->player.dir_x = RIGHT ? g->player.dir_x * cos(g->player.rot) - \
					g->player.dir_y * sin(g->player.rot) : g->player.dir_x * \
					cos(-g->player.rot) - g->player.dir_y * sin(-g->player.rot);
	g->player.dir_y = RIGHT ? tmp_dir * sin(g->player.rot) + g->player.dir_y * \
		cos(g->player.rot) : tmp_dir * sin(-g->player.rot) + g->player.dir_y * \
															cos(-g->player.rot);
	g->player.plane_x = RIGHT ? g->player.plane_x * cos(g->player.rot) - \
				g->player.plane_y * sin(g->player.rot) : g->player.plane_x * \
				cos(-g->player.rot) - g->player.plane_y * sin(-g->player.rot);
	g->player.plane_y = RIGHT ? tmp_plane * sin(g->player.rot) + \
	g->player.plane_y * cos(g->player.rot) : tmp_plane * sin(-g->player.rot) \
									+ g->player.plane_y * cos(-g->player.rot);
	start_wolf(g);
	launch_mini_map(g);
	return (1);
}

int		get_pos(t_global *g, int key)
{
	if (!(UP) && !(DOWN))
		return (0);
	if (UP)
	{
		if (g->map[(int)(g->player.pos_y)][(int)(g->player.pos_x \
					+ g->player.dir_x * g->player.speed * 2)] <= 19)
			g->player.pos_x += g->player.dir_x * g->player.speed;
		if (g->map[(int)(g->player.pos_y + g->player.dir_y * g->player.speed * 2)]\
				[(int)(g->player.pos_x)] <= 19)
			g->player.pos_y += g->player.dir_y * g->player.speed;
	}
	else if (DOWN)
	{
		if (g->map[(int)(g->player.pos_y)][(int)(g->player.pos_x \
					- g->player.dir_x * g->player.speed * 2)] <= 19)
			g->player.pos_x -= g->player.dir_x * g->player.speed;
		if (g->map[(int)(g->player.pos_y - g->player.dir_y * g->player.speed * 2)]\
				[(int)(g->player.pos_x)] <= 19)
			g->player.pos_y -= g->player.dir_y * g->player.speed;
	}
	start_wolf(g);
	launch_mini_map(g);
	return (1);
}

int		close_mouse(int key, t_global *g)
{
	(void)key;
	(void)g;
	exit(1);
	return (0);
}

int		close_map(t_global *g, int key)
{
	if (!(ESCAPE) || !g)
		return (0);
	exit(EXIT_SUCCESS);
}

int		deal_key(int key, t_global *g)
{
	int i;

	i = 0;
	while ((i < MAX_FUNC) && !g->key_func[i](g, key))
		i++;
	return (0);
}
