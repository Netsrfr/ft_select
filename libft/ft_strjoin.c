/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:42:38 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/26 15:42:38 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dest, char const *src)
{
	char	*result;
	int		i;
	int		n;

	i = -1;
	n = -1;
	if (!(result = (char*)ft_memalloc(ft_strlen(dest) + ft_strlen(src) + 1)))
		return (0);
	while (dest[i = i + 1])
		result[i] = dest[i];
	while (src[n = n + 1])
	{
		result[i] = src[n];
		i++;
	}
	result[i] = '\0';
	return (result);
}
