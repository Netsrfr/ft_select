/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:18:23 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/22 21:18:23 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = -1;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	while ((i = i + 1) < n)
	{
		dest[i] = source[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)&dest[i + 1]);
	}
	return (0);
}
