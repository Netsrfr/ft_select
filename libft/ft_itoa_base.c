/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:37:44 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/02/13 14:37:44 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
** Conversion to smaller base may cause result to be longer than initial input.
** Solution is to temporarily store numbers in an array to determine length
** prior to setting result. Array size of 34 is used to allow min int in to be
** stored in base 2 with a null terminating character.
*/

/*
** Malloc always allocates enough memory for largest conversion ie: base 16 to
** base 2. Although extra memory may be allocated the impact to performance
** should be negligible.
*/

char	*negative(char *result, long *num, int base, int *j)
{
	if (base == 10)
	{
		result[0] = '-';
		*num = (*num * -1);
		*j = 1;
	}
	else
	{
		*num += UINT_MAX;
		*num = *num + 1;
	}
	return (result);
}

char	*ft_itoa_base(long num, int base)
{
	char	*base_values;
	char	*result;
	int		i;
	int		j;
	int		temp[21];

	base_values = ft_strdup("0123456789ABCDEF");
	if (num == 0)
		return (result = ft_strdup("0"));
	j = 0;
	if (!(result = ft_memalloc(sizeof(char) * ft_mylog(num) * 4)))
		return (0);
	if (num <= 0)
		result = negative(result, &num, base, &j);
	i = 0;
	while (num != 0)
	{
		temp[i++] = num % base;
		num = num / base;
	}
	while (--i >= 0)
		result[j++] = base_values[temp[i]];
	return (result);
}

char	*ft_itoa_base_unsigned(unsigned long long num, int base)
{
	char	*base_values;
	char	*result;
	int		i;
	int		j;
	int		temp[21];

	base_values = ft_strdup("0123456789ABCDEF");
	if (num == 0)
		return (result = ft_strdup("0"));
	j = 0;
	if (!(result = ft_memalloc(sizeof(char) * ft_mylog_unsigned(num) * 4)))
		return (0);
	i = 0;
	while (num != 0)
	{
		temp[i++] = num % base;
		num = num / base;
	}
	while (--i >= 0)
		result[j++] = base_values[temp[i]];
	return (result);
}
