/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 11:46:14 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/26 11:46:14 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*bigcast;

	i = 0;
	j = 0;
	bigcast = (char*)big;
	while (big[i] & little[j] && i < len)
	{
		while (little[j] != big[i] && little[j] && big[i] && i < len)
			i++;
		i = i - 1;
		while (little[j] == big[i = i + 1] && little[j] && big[i] && i < len)
			j++;
		if (little[j] == '\0')
			return (&bigcast[i - ft_strlen(little)]);
		else if (big[i] == '\0')
			return (0);
		i = i - (j - 1);
		j = 0;
	}
	if (little[j] == '\0')
		return (&bigcast[i - ft_strlen(little)]);
	else
		return (0);
}
