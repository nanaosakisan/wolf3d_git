/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:48:08 by iporsenn          #+#    #+#             */
/*   Updated: 2018/10/01 16:40:02 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

static int	get_color(int id)
{
	if (id == 1)
		return (0x00990099);
	return (0x00FFFFFF);
}

void	raycast_loop(t_global *g)
{
	int			x;
	long double cam_x;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	float		coord_src[2];
	float		coord_dest[2];

	x = -1;
	while (++x < WIDTH)
	{
		g->ray.map_x = (int)g->player.pos_x;
		g->ray.map_y = (int)g->player.pos_y;
		cam_x = 2 * x / (long double)WIDTH - 1;
		hit = 0;
		g->ray.dir_x = g->player.dir_x + g->player.plane_x * cam_x;
		g->ray.dir_y = g->player.dir_y + g->player.plane_y * cam_x;
		g->ray.deltadist_x = sqrt(1 + (g->ray.dir_y * g->ray.dir_y) / \
								(g->ray.dir_x * g->ray.dir_x));
		g->ray.deltadist_y = sqrt(1 + (g->ray.dir_x * g->ray.dir_x) / \
												(g->ray.dir_y * g->ray.dir_y));
		step_x = (g->ray.dir_x < 0) ? -1 : 1;
		g->ray.sidedist_x = (g->ray.dir_x < 0) ? \
					((g->player.pos_x - g->ray.map_x) * g->ray.deltadist_x) \
				: ((g->ray.map_x + 1.0 - g->player.pos_x) * g->ray.deltadist_x);
		step_y = (g->ray.dir_y < 0) ? -1 : 1;
		g->ray.sidedist_y = (g->ray.dir_y < 0) ? \
					((g->player.pos_y - g->ray.map_y) * g->ray.deltadist_y) \
				: ((g->ray.map_y + 1.0 - g->player.pos_x) * g->ray.deltadist_y);
		while (hit == 0)
		{
			if (g->ray.sidedist_x < g->ray.sidedist_y)
			{
				g->ray.sidedist_x += g->ray.deltadist_x;
				g->ray.map_x += step_x;
				side = 0;
			}
			else
			{
				g->ray.sidedist_y += g->ray.deltadist_y;
				g->ray.map_y += step_y;
				side = 1;
			}
			if (g->map[g->ray.map_y][g->ray.map_x] == 1)
				hit = 1;
		}
		g->ray.perp_walldist = (side == 0) ? \
			(g->ray.map_x - g->player.pos_x + (1 - step_x) / 2) / g->ray.dir_x \
		: (g->ray.map_y - g->player.pos_y + (1 - step_y) / 2) / g->ray.dir_y;
		printf("perp_walldist = %Lf\n", g->ray.perp_walldist);
		line_height = (g->ray.perp_walldist > 0) ? \
								(int)(HEIGHT / g->ray.perp_walldist) : HEIGHT;
		printf("line_height = %d\n", line_height);
		coord_src[0] = (float)(-line_height / 2 + HEIGHT / 2);
		coord_src[0] = (coord_src[0] < 0) ? 0 : coord_src[0];
		coord_dest[0] = (float)(line_height / 2 + HEIGHT / 2);
		coord_dest[0] = (coord_dest[0] >= HEIGHT) ? HEIGHT - 1 : coord_dest[0];
		coord_src[1] = x;
		coord_dest[1] = x;
		g->color = get_color(g->map[g->ray.map_y][g->ray.map_x]);
		draw_segment(coord_src, coord_dest, g);
	}
}
