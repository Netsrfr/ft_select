/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:33:22 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/22 19:33:22 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*scast;
	size_t			i;

	i = -1;
	scast = (unsigned char*)s;
	while ((i = i + 1) < n)
		scast[i] = 0;
}
