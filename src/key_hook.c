/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:57:24 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/22 13:57:26 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

int		close_map(t_global *global, int key)
{
	if (key != 53)
		return (0);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	free_parse(global->wall, global->height);
	global->img.p_mlx = NULL;
	global->img.p_win = NULL;
	global->img.p_img = NULL;
	global->img.img_addr = NULL;
	exit(EXIT_SUCCESS);
}

int		deal_key(int key, t_global *global)
{
	int i;

	i = 0;
	while ((i < global->len_key) && !global->key_func[i](global, key))
		i++;
	return (0);
}
