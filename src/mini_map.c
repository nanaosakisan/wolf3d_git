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

void	draw_map(t_global *global)
{
	int i;
	int j;

	i = -1;
	while (++i < global->width)
	{
		j = -1;
		while (++j < global->height)
		{
			if (global->wall[j][i] == 1)
				draw_white_square(i * SQUARE, j * SQUARE, global);
			else
				draw_black_square(i * SQUARE, j * SQUARE, global);
		}
	}
}


// static int		get_thread_id(pthread_t id, pthread_t *thread)
// {
// 	int i;
//
// 	i = 0;
// 	while (i < THREAD && !pthread_equal(id, thread[i]))
// 		i++;
// 	return (i);
// }
//
// static void		*launch_thread(void *data)
// {
// 	int			start;
// 	int			end;
// 	int			padding;
// 	int			i;
// 	t_global	*global;
//
// 	global = (t_global *)data;
// 	padding = WIDTH / THREAD;
// 	start = get_thread_id(pthread_self(), global->thread) * padding;
// 	end = start + padding + 1;
// 	while (++start < WIDTH && start < end && start < SQUARE)
// 	{
// 		i = -1;
// 		while (++i < HEIGHT && i < SQUARE)
// 			draw_map(global);
// 	}
// 	pthread_exit(NULL);
// 	return (NULL);
// }

void	launch_mini_map(t_global *global)
{
	// int i;
    //
	// i = -1;
	// while (++i < THREAD)
	// 	pthread_create(&global->thread[i], NULL, launch_thread, global);
	// i = -1;
	// while (++i < THREAD)
	// 	pthread_join(global->thread[i], NULL);
	draw_map(global);
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
}
