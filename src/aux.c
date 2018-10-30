/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:18:14 by iporsenn          #+#    #+#             */
/*   Updated: 2018/10/27 16:18:16 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

char	*get_path(int i, char *type)
{
	char	*path;
	char	*tmp;
	char	*tmp_2;

	path = ft_strjoin("textures/", type);
	tmp = path;
	tmp_2 = ft_itoa(i);
	path = ft_strjoin(path, tmp_2);
	free(tmp);
	free(tmp_2);
	tmp = path;
	path = ft_strjoin(path, ".xpm");
	free(tmp);
	return (path);
}

int		get_thread_id(pthread_t id, pthread_t *thread)
{
	int i;

	i = 0;
	while (i < THREAD && !pthread_equal(id, thread[i]))
		i++;
	return (i);
}

void	free_tmp(int **tmp, int i)
{
	while (--i > -1)
		free(tmp[i]);
	free(tmp);
}

void	get_tex_bonus(t_global *g, t_local *l)
{
	if (g->map[l->ray.map_y][l->ray.map_x] >= 10 && \
			g->map[l->ray.map_y][l->ray.map_x] < 20)
	{
		l->t_type = 0;
		l->t_id = g->map[l->ray.map_y][l->ray.map_x] - 10;
	}
	else if (g->map[l->ray.map_y][l->ray.map_x] >= 20 && \
			g->map[l->ray.map_y][l->ray.map_x] < 30)
	{
		l->t_type = 1;
		l->t_id = g->map[l->ray.map_y][l->ray.map_x] - 20;
	}
	else if (g->map[l->ray.map_y][l->ray.map_x] >= 30 && \
			g->map[l->ray.map_y][l->ray.map_x] < 40)
	{
		l->t_type = 2;
		l->t_id = g->map[l->ray.map_y][l->ray.map_x] - 30;
	}
}
