/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:33:52 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/22 19:33:52 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scast;

	scast = (unsigned char*)s;
	i = -1;
	while ((i = i + 1) < n)
	{
		if (scast[i] == (unsigned char)c)
			return ((void*)&scast[i]);
	}
	return (NULL);
}
