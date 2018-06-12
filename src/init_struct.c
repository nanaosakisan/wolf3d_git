/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:40:51 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/05 17:40:53 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

void		init_global(t_global *global)
{
	global->name = NULL;
	global->wall = NULL;
	global->width = 0;
	global->height = 0;
}
