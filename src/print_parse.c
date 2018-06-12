/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:47:40 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/12 14:47:41 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

void	print_parse(t_global *global)
{
	int i;
	int j;

	i = -1;
	while (++i < global->width)
	{
		j = -1;
		while (++j < global->height)
		{
			ft_putnbr(global->wall[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
