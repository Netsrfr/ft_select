/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:15:51 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/24 20:15:51 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*scast;

	i = (int)ft_strlen(s);
	scast = (char*)s;
	if (c == 0)
		return (&scast[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == c)
			return (&scast[i]);
		i--;
	}
	return (0);
}
