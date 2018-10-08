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
	ft_putendl("buh");
    if (key != LEFT && key != RIGHT)
        return (0);
    if (ft_between(0, g->player.dir_y, 1))
    {
        g->player.dir_x += (key == LEFT ? -0.1 : 0.1);
        if (key == LEFT)
            g->player.dir_y += (g->player.dir_x > 0 ? 0.1 : -0.1);
        else
            g->player.dir_y += (g->player.dir_x > 0 ? -0.1 : 0.1);
    }
    else
    {
        g->player.dir_x += (key == LEFT ? 0.1 : -0.1);
        if (key == LEFT)
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
	ft_putendl("arrrggggg");
    if (key != UP && key != DOWN)
        return (0);
    g->player.pos_x += (key == UP ? g->player.dir_x : -g->player.dir_x);
    g->player.pos_y += (key == UP ? g->player.dir_y : -g->player.dir_y);
	mlx_destroy_image(g->mlx, g->p_img);
	raycast_loop(g);
    return (1);
}

int		close_map(t_global *global, int key)
{
	ft_putendl("blblblblblbl");
	if (key != 53)
		return (0);
	free_parse(global->map, global->max_y);
	exit(EXIT_SUCCESS);
}

int		deal_key(int key, t_global *global)
{
	int i;

	printf("key = %d\n", key);
	i = 0;
	// if (key == 53)
	// 	close_map(global, key);
	printf("i = %d\n", i);
	while ((i < global->len_key) && !global->key_func[i](global, key))
	{
		ft_putendl("nyup");
		i++;
	}
	return (0);
}
