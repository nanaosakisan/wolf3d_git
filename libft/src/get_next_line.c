/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:40:12 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/06 14:22:46 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*dest;
	int		len;

	if (!s1 || !s2)
		return (0);
	dest = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, (s2));
	ft_strdel(&s1);
	return (dest);
}

static int	read_reste(char **reste, char **line, size_t len)
{
	int		i;
	int		end;
	char	tmp[len + 1];

	tmp[len] = '\0';
	end = 0;
	if (!(*line = ft_strnew(len)))
		return (-1);
	i = -1;
	while ((*reste)[++i] != '\n' && (*reste)[i] != '\0')
		(*line)[i] = (*reste)[i];
	if ((*reste)[i] == '\n')
	{
		end = 1;
		i++;
	}
	ft_bzero(tmp, len + 1);
	ft_strcpy(tmp, *reste + i);
	ft_strdel(reste);
	if (end == 1)
	{
		*reste = ft_strdup(tmp);
		return (1);
	}
	return (0);
}

static int	read_buff(char *buff, char **line, char **reste, size_t len)
{
	int		i;
	char	tmp[len + 1];

	ft_bzero(tmp, len + 1);
	i = -1;
	while (buff[++i] != '\n' && buff[i])
		tmp[i] = buff[i];
	if (!(*line))
	{
		if (!(*line = ft_strdup(tmp)))
			return (0);
	}
	else
		*line = ft_strjoin_free(*line, tmp);
	if (buff[i] == '\n')
	{
		if (*reste)
			ft_strdel(reste);
		if (!(*reste = ft_strnew(len - i)))
			return (0);
		i++;
		ft_strcpy(*reste, buff + i);
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*reste = NULL;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	ret = 0;
	if (ft_strlen(reste))
		if (read_reste(&reste, line, ft_strlen(reste)) == 1)
			return (1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (read_buff((char*)&buff, line, &reste, BUFF_SIZE) == 1)
			return (1);
	}
	if (!ft_strlen(reste) && ret == 0 && !ft_strlen(*line))
	{
		ft_strdel(&reste);
		return (0);
	}
	return (ret != -1) ? 1 : -1;
}
