/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:06:44 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/28 11:06:44 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	counter;

	if (!(result = (char*)ft_memalloc(len + 1)))
		return (0);
	counter = 0;
	while (len > 0)
	{
		result[counter] = s[start];
		counter++;
		start++;
		len--;
	}
	result[counter] = '\0';
	return (result);
}
