/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:57:35 by iporsenn          #+#    #+#             */
/*   Updated: 2017/11/22 15:57:37 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
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
	return (dest);
}
