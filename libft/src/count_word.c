/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:15:09 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/10 14:15:11 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			count_word(const char *s, char c)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (!s || !c)
			return (0);
		if (s[i] == c && !s[i - 1])
			i++;
		if ((s[i - 1] != c && s[i] == c) || (!s[i + 1] && s[i] != c))
			cpt++;
		i++;
	}
	return (cpt);
}
