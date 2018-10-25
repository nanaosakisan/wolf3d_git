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

static void	mlx_pixel_put_image(t_global *global, int x, int y, int color)
{
	int i;

	if (global->mini_map.endian == 0)
	{
		i = (global->mini_map.size * y) + (x * (global->mini_map.bpp / 8));
		global->mini_map.img_addr[i] = mlx_get_color_value(global->mlx, color);
		global->mini_map.img_addr[i + 1] = mlx_get_color_value(global->mlx, \
																	color >> 8);
		global->mini_map.img_addr[i + 2] = mlx_get_color_value(global->mlx, \
																color >> 16);
	}
	else
	{
		i = (global->mini_map.size * y) + (x * (global->mini_map.bpp / 8));
		global->mini_map.img_addr[i] = mlx_get_color_value(global->mlx, \
																color >> 16);
		global->mini_map.img_addr[i + 1] = mlx_get_color_value(global->mlx, \
																	color >> 8);
		global->mini_map.img_addr[i + 2] = mlx_get_color_value(global->mlx, \
																		color);
	}
}

static void	draw_white_square(int x, int y, t_global *global)
{
	int i;
	int len_x;
	int	len_y;

	len_x = x + SQUARE;
	len_y = y + SQUARE;
	while (x < WIDTH && x <= len_x)
	{
		i = y;
		while (++i <= HEIGHT && i <= len_y)
			mlx_pixel_put_image(global, x, i, 0xFFFFFF);
		x++;
	}
}

static void	draw_black_square(int x, int y, t_global *global)
{
	int i;
	int len;

	len = x + SQUARE;
	while (x < WIDTH && x < len)
	{
		i = y;
		while (++i < HEIGHT && i <= y + SQUARE)
			mlx_pixel_put_image(global, x, i, 0x000000);
		x++;
	}
}

void		launch_mini_map(t_global *g)
{
	int i;
	int j;

	g->mini_map.p_img = mlx_new_image(g->mlx, WIDTH_UI, HEIGHT);
	g->mini_map.img_addr = mlx_get_data_addr(g->mini_map.p_img, \
					&g->mini_map.bpp, &g->mini_map.size, &g->mini_map.endian);
	i = -1;
	while (++i < g->max_x)
	{
		j = -1;
		while (++j < g->max_y)
		{
			printf()
			if (((g->map[j][i] / 10) >= 2) && ((g->map[j][i] / 10) <= 9))
				draw_white_square(i * SQUARE, j * SQUARE, g);
			else
				draw_black_square(i * SQUARE, j * SQUARE, g);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->mini_map.p_img, 0, 0);
}
