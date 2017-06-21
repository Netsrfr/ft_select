/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:29:25 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/21 22:29:25 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	else
		while (i < ft_strlen(s1) && i < len)
		{
			result[i] = s1[i];
			i++;
		}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (!(result = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (0);
	else
		while (i < len)
		{
			result[i] = s1[i];
			i++;
		}
	result[i] = '\0';
	return (result);
}
