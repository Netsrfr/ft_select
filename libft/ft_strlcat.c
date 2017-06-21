/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 19:20:44 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/24 19:20:44 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	ids;

	n = -1;
	i = ft_strlen(dst);
	ids = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (size - (ft_strlen(dst) + 1) > 0 && src[n = n + 1] != '\0')
	{
		dst[i] = src[n];
		i++;
	}
	dst[i] = '\0';
	return (ids + ft_strlen(src));
}
