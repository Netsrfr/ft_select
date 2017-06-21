/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:55:17 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/21 16:55:18 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SI(x) (*str == x)

long long int			ft_atoi(char *str)
{
	int				neg;
	long long int	result;

	neg = 1;
	result = 0;
	while (SI(' ') || SI('\t') || SI('\n') || SI('\v') || SI('\r') || SI('\f'))
		(*str)++;
	if (SI('-') && *(str + 1) != '-' && *(str + 1) != '+')
	{
		neg = -neg;
		str++;
	}
	if (SI('+') && *(str + 1) != '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + (*str - 48);
		str++;
	}
	return (result * neg);
}

unsigned long long int	ft_atoi_hex(char **str)
{
	unsigned long long int	result;

	result = 0;
	(*str)++;
	(*str)++;
	while ((**str >= '0' && **str <= '9') || (**str >= 'A' && **str <= 'F'))
	{
		result = result * 16;
		if (**str >= '0' && **str <= '9')
			result = result + (**str - 48);
		else
			result = result + (**str - 55);
		(*str)++;
	}
	return (result);
}
