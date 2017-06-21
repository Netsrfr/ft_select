/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 19:24:46 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/24 19:24:47 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*scast;

	i = 0;
	scast = (char*)s;
	if (c == 0)
		return (&scast[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return (&scast[i]);
		i++;
	}
	return (0);
}
