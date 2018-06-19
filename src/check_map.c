/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:25:04 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/12 17:25:05 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

static int ft_strlen_remake(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (0);
	}
	return (i);
}

static int	check_delimitation(char *line, int cpt, t_global *global)
{
	int				i;
	size_t			tmp;
	static size_t	len = 0;

	tmp = ft_strlen_remake(line);
	if (len == 0)
		len = ft_strlen(line);
	if (tmp != len)
		return (0);
	if (cpt == 0 || cpt == global->width - 1)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[len - 1] != '1')
			return (0);
	}
	return (1);
}

static int	check_number(char *line, int cpt, t_global *global, int *tmp)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '0')
		{
			if (*tmp == 0)
			{
				global->x_init = i / 2;
				global->y_init = cpt;
			}
			(*tmp)++;
		}
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ')
			return (0);
	}
	return (1);
}

int			check_map(char *line, int cpt, t_global *global, int *tmp)
{
	if ((!line) || check_delimitation(line, cpt, global) != 1
		|| check_number(line, cpt, global, tmp) != 1)
		return (0);
	return (1);
}
