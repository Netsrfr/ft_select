/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:06:12 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/27 10:06:12 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*buffer;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (0);
	buffer = (char*)mem;
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	return (mem);
}
