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

typedef struct	s_global
{
	char	*name;
	int		**wall;
}				t_global;

void			init_global(t_global *global);
int				main(int ac, char **av);
int				parsing(t_global *global, int fd);

#endif
