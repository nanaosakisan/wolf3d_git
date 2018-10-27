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

	path = ft_strjoin("textures/", type);
	tmp = path;
	path = ft_strjoin(path, ft_itoa(i));
	free(tmp);
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
