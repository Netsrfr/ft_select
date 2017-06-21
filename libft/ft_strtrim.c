/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:46:19 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/27 14:46:20 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s)
{
	char	*str;
	size_t	i;
	size_t	n;
	int		counter;

	i = 0;
	counter = 0;
	n = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
		n--;
	if (i == ft_strlen(s))
		return (str = "");
	if (!(str = (char*)ft_memalloc(sizeof(char) * ((n - i) + 2))))
		return (0);
	while (i <= n && s[0] != '\0')
	{
		str[counter] = s[i];
		i++;
		counter++;
	}
	free(s);
	return (str);
}
