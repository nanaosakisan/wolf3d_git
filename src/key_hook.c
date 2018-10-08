/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:57:24 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/22 13:57:26 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

int        get_dir(t_global *g, int key)
{
    if (!(LEFT) && !(RIGHT))
        return (0);
    if (ft_between(0, g->player.dir_y, 1))
    {
        g->player.dir_x += (LEFT ? -0.1 : 0.1);
        if (LEFT)
            g->player.dir_y += (g->player.dir_x > 0 ? -0.1 : 0.1);
        else
            g->player.dir_y += (g->player.dir_x > 0 ? 0.1 : -0.1);
    }
    else
    {
        g->player.dir_x += (LEFT ? 0.1 : -0.1);
        if (LEFT)
            g->player.dir_y += (g->player.dir_x > 0 ? 0.1 : -0.1);
        else
            g->player.dir_y += (g->player.dir_x > 0 ? -0.1 : 0.1);
    }
	mlx_destroy_image(g->mlx, g->p_img);
	raycast_loop(g);
    return (1);
}

int        get_pos(t_global *g, int key)
{
	if (!(UP) && !(DOWN))
        return (0);
    g->player.pos_x += (UP ? g->player.dir_x : -g->player.dir_x) * 0.1;
    g->player.pos_y += (UP ? g->player.dir_y : -g->player.dir_y) * 0.1;
	mlx_destroy_image(g->mlx, g->p_img);
	raycast_loop(g);
    return (1);
}

int		close_map(t_global *g, int key)
{
	if (ESCAPE)
		return (0);
	free_parse(g->map, g->max_y);
	exit(EXIT_SUCCESS);
}

int		deal_key(int key, t_global *g)
{
	int i;

	i = 0;
	while ((i < g->len_key) && !g->key_func[i](g, key))
		i++;
	return (0);
}
