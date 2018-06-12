/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:26:24 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/05 17:26:25 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

int		main(int ac, char **av)
{
	t_global	global;
	int			fd;

	if (ac != 2)
		error("usage: ./fdf filename");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error("open() failed");
		global.name = av[1];
		lauchn_parse(&global, fd, av);
		print_parse(&global);
	}
	return (0);
}
