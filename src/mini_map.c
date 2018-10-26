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
			((int*)g->mini_map.img_addr)[(int)(x + i * WIDTH)] = 0x00FFFFFF;
		x++;
	}
}

// static void	draw_black_square(int x, int y, t_global *g)
// {
// 	int i;
// 	int len;
//
// 	len = x + SQUARE;
// 	while (x < WIDTH && x < len)
// 	{
// 		i = y;
// 		while (++i < HEIGHT && i <= y + SQUARE)
// 			((int*)g->mini_map.img_addr)[(int)(x + i * WIDTH_UI)] = 0xFF000000;
// 		x++;
// 	}
// }

void		launch_mini_map(t_global *g)
{
	int i;
	int j;

	g->mini_map.p_img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->mini_map.img_addr = mlx_get_data_addr(g->mini_map.p_img, \
					&g->mini_map.bpp, &g->mini_map.size, &g->mini_map.endian);
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			((int*)g->mini_map.img_addr)[(int)(i + j * WIDTH)] = 0xFF000000;
	}
	i = -1;
	while (++i < g->max_x)
	{
		j = -1;
		while (++j < g->max_y)
		{
			if ((g->map[j][i] >= 20) && (g->map[j][i] <= 29))
				draw_white_square(i * SQUARE, j * SQUARE, g);
			// else
			// 	draw_black_square(i * SQUARE, j * SQUARE, g);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->mini_map.p_img, 0, 0);
}
