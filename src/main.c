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
		init_global(&global);
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error("open() failed");
		global.name = av[1];
		launch_parse(&global, fd, av);
		global.img.p_mlx = mlx_init();
		global.img.p_win = mlx_new_window(global.img.p_mlx, WIDTH + WIDTH_UI, \
			 									HEIGHT + HEIGHT_UI, "wolf3d");
		global.img.p_img = mlx_new_image(global.img.p_mlx, WIDTH, HEIGHT);
		global.img.img_addr = mlx_get_data_addr(global.img.p_img, \
			&global.img.bpp, &global.img.size, &global.img.endian);
		launch_mini_map(&global);
		mlx_put_image_to_window(global.img.p_mlx, global.img.p_win, \
										global.img.p_img, WIDTH_UI, HEIGHT_UI);
		mlx_hook(global.img.p_win, 2, (1L << 0), deal_key, &global);
		mlx_loop(global.img.p_mlx);
	}
	return (0);
}


// int		main(int ac, char **av)
// {
// 	SDL_Window	*p_win;
//
// 	if (!ac && !av)
// 		return (0);
// 	SDL_Init(SDL_INIT_VIDEO);
// 	p_win = NULL;
// 	p_win = SDL_CreateWindow("Buh", SDL_WINDOWPOS_CENTERED, \
// 	SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
// 	SDL_Delay(30000);
// 	SDL_DestroyWindow(p_win);
// 	SDL_Quit();
// 	return (0);
// }
