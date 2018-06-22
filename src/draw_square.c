/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:19:39 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/19 17:19:41 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

void	draw_square(int x, int y, t_global *global)
{
	int i;
	int j;

	i = -1;
	while (++i < global->width && i < x)
	{
		j = -1;
		while (++j < global->height && j < y)
		{
			mlx_pixel_put_to_image(global, i, j, 0xFFFFFF);
		}
	}
}
