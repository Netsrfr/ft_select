/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:35:44 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/10/31 20:35:44 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_c(char const *s, int delim)
{
	char	*str;
	size_t	i;
	size_t	n;
	int		counter;

	i = 0;
	counter = 0;
	if (ft_strlen(s) != 0)
		n = ft_strlen(s) - 1;
	else
		n = 0;
	while (s[i] != delim)
		i++;
	while (s[n] != delim)
		n--;
	if (!(str = (char*)ft_memalloc((n - i) + 2)))
		return (0);
	while (i <= n && s[0] != '\0')
	{
		str[counter] = s[i];
		i++;
		counter++;
	}
	str[i] = '\0';
	return (str);
}
