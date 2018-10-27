/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:47:50 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/25 12:47:52 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

static void	draw_white_square(int x, int y, t_global *g)
{
	int i;
	int len_x;
	int	len_y;

	len_x = x + SQUARE;
	len_y = y + SQUARE;
	while (x < WIDTH && x <= len_x)
	{
		i = y - 1;
		while (++i <= HEIGHT && i <= len_y)
			((int*)g->mini_map.data)[(int)(x + i * WIDTH)] = 0x00FFFFFF;
		x++;
	}
}

static void	draw_transparente_square(int x, int y, t_global *g)
{
	int i;
	int len_x;
	int	len_y;

	len_x = x + SQUARE;
	len_y = y + SQUARE;
	while (x < WIDTH && x <= len_x)
	{
		i = y - 1;
		while (++i <= HEIGHT && i <= len_y)
			((int*)g->mini_map.data)[(int)(x + i * WIDTH)] = 0xFFFFFFFF;
		x++;
	}
}

static void	draw_player(t_global *g, int x, int y)
{
	float	i;
	float	j;
	float	len_x;
	float	len_y;

	i = SQUARE * x;
	len_x = i + SQUARE;
	while (i < WIDTH && i <= len_x)
	{
		j = SQUARE * y;
		len_y = j + SQUARE;
		while (++j < HEIGHT && j <= len_y)
			((int*)g->mini_map.data)[(int)(i + j * WIDTH)] = 0x00FF0000;
		i++;
	}
}

static void	loop_draw(int i, int j, t_global *g)
{
	if ((g->map[j][i] >= 20) && (g->map[j][i] <= 29))
		draw_white_square(i * SQUARE, j * SQUARE, g);
	else
		draw_transparente_square(i * SQUARE, j * SQUARE, g);
	if (i == (int)g->player.pos_x && j == (int)g->player.pos_y)
		draw_player(g, i, j);
}

void		launch_mini_map(t_global *g)
{
	int i;
	int j;

	g->mini_map.p_img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->mini_map.data = mlx_get_data_addr(g->mini_map.p_img, &g->mini_map.bpp, \
										&g->mini_map.size, &g->mini_map.endian);
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			((int*)g->mini_map.data)[(int)(i + j * WIDTH)] = 0xFF000000;
	}
	i = -1;
	while (++i < g->max_x)
	{
		j = -1;
		while (++j < g->max_y)
			loop_draw(i, j, g);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->mini_map.p_img, 0, 0);
}
