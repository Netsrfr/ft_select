/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:10:50 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/24 12:10:50 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cast;
	unsigned char	*s2cast;
	size_t			i;

	i = 0;
	s1cast = (unsigned char*)s1;
	s2cast = (unsigned char*)s2;
	while (i < n && s1cast[i] == s2cast[i])
		i++;
	if (i == n)
		return (0);
	else
		return (s1cast[i] - s2cast[i]);
}
