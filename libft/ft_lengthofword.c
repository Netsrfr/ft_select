/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengthofword.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:09:24 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/10/03 10:09:24 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lengthofword(char const *str, char delim, int i)
{
	int	length;

	length = 0;
	while (str[i] != delim && str[i])
	{
		length++;
		i++;
	}
	return (length);
}
