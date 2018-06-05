/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:25:20 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/05 17:25:22 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf_3d.h"

static void		*malloc_wall(t_global *global, char *line)
{
	int len;
	int i;

	len = ft_count_word(line);
	if (!(global->wall = (int**)ft_memalloc(sizeof(int*) * 2)))
		return (NULL);
	i = -1;
	while (++i < 2)
	{
		if (!(global->wall[i] = (int*)ft_memalloc(sizeof(int) * len)))
			return (NULL);
	}
	return (NULL);
}

int			parsing(t_global *global, int fd)
{

}
