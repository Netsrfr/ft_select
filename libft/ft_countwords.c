/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:08:24 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/10/03 10:08:24 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char delim)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == delim)
		{
			i++;
			if (str[i] == '\0')
				return (words);
		}
		words++;
		while (str[i] != delim)
		{
			i++;
			if (str[i] == '\0')
				return (words);
		}
	}
	return (words);
}
