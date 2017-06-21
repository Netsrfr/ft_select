/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:34:40 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/22 19:34:40 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1cast;
	unsigned char	*s2cast;

	i = 0;
	s1cast = (unsigned char*)s1;
	s2cast = (unsigned char*)s2;
	while (s1[i] && s1cast[i] == s2cast[i])
		i++;
	return (s1cast[i] - s2cast[i]);
}
