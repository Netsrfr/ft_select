/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:07:24 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/23 13:07:24 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*dest;
	unsigned int	i;

	i = -1;
	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	if (dst < src)
		while ((i = i + 1) < len)
			dest[i] = source[i];
	else if (len > 0)
	{
		i = len;
		while ((i = i - 1) > 0)
			dest[i] = source[i];
		dest[i] = source[i];
	}
	return (dst);
}
