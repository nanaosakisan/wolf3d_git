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

typedef struct	s_global
{
	char	*name;
	int		**wall;
	int		width;
	int		height;
}				t_global;

int				check_map(char *line, int cpt);
void			free_array(char **array, int len_array);
void			init_global(t_global *global);
int				main(int ac, char **av);
int				lauchn_parse(t_global *global, int fd, char **av);
void			print_parse(t_global *global);

#endif
