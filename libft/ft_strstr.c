/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:23:30 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/24 20:23:30 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int l;
	int b;
	int remember;

	b = 0;
	if (!*little)
		return ((char *)big);
	while (big[b])
	{
		remember = b + 1;
		l = 0;
		while (big[b] == little[l])
		{
			b++;
			l++;
			if (little[l] == '\0')
				return ((char *)(big + remember - 1));
		}
		b = remember;
	}
	return (NULL);
}
