/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:31:13 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/23 11:31:26 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	unsigned int	i;

	i = -1;
	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while ((i = i + 1) < n)
		dest[i] = source[i];
	return (dst);
}
