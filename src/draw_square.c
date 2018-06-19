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

void	draw_square(float *height, float *width, t_global *global)
{
	int i;
	int j;

	i = -1;
	while (++i < global->height)
	{
		j = -1;
		while (++j < global->width)
		{
			draw_segment(height, width, global);
		}
	}
}
