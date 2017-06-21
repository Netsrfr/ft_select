/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:43:55 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/21 22:43:55 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bcast;

	i = 0;
	bcast = (unsigned char*)b;
	while (i < len)
	{
		bcast[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
