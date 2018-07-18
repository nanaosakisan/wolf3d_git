/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:09:45 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/04 14:09:47 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>
// # include "../SDL2-2.0.8/include/SDL.h"

# define WIDTH 600
# define HEIGHT 600
# define WIDTH_UI 100
# define HEIGHT_UI 100
# define THREAD 10
# define SQUARE 16

typedef	struct s_img
{
	void 	*p_mlx;
	void	*p_win;
	void	*p_img;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
}				t_img;

typedef struct	s_map
{
	void	*p_img;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
}				t_map;

typedef struct	s_player
{
	int		x;
	int 	y;
	int		height;
	int		angle;
}				t_player;

typedef struct	s_global
{
	t_img	img;
	t_map	map;
	char	*name;
	int		**wall;
	int		width;
	int		height;
	int		x_init;
	int		y_init;
	int		color;
	int		(*key_func[1])(struct s_global*, int);
	int		len_key;
	pthread_t	thread[THREAD];
}				t_global;

int				check_map(char *line, int cpt, t_global *global, int *tmp);
int				close_map(t_global *global, int key);
int				deal_key(int key, t_global *global);
void			draw_segment(float *coord_src, float *coord_dst, \
															t_global *global);
void			draw_white_square(int x, int y, t_global *global);
void			draw_black_square(int x, int y, t_global *global);
void			free_array(char **array, int len_array);
void			free_parse(int **wall, int len_array);
void			init_global(t_global *global);
int				main(int ac, char **av);
void			mlx_pixel_put_to_image(t_global *global, int x, int y, \
																	int color);
void			launch_mini_map(t_global *global);
int				launch_parse(t_global *global, int fd, char **av);
void			print_parse(t_global *global);

#endif
