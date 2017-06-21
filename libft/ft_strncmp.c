/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:24:14 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/26 12:24:14 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cast;
	unsigned char	*s2cast;

	i = 0;
	s1cast = (unsigned char*)s1;
	s2cast = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (s1[i] && s1cast[i] == s2cast[i] && n != 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (s1cast[i - 1] - s2cast[i - 1]);
	else
		return (s1cast[i] - s2cast[i]);
}
