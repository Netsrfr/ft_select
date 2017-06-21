/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:29:44 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/08 15:29:44 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned(unsigned long long n)
{
	char	*str;
	int		i;

	i = (ft_mylog_unsigned(n) - 1);
	if (!(str = ft_memalloc(sizeof(char) * ft_mylog(n) + 1)))
		return (0);
	str[ft_mylog_unsigned(n)] = '\0';
	while (n >= 10)
	{
		str[i] = (n % 10 + 48);
		i--;
		n = (n / 10);
	}
	if (n < 10)
		str[i] = (n % 10 + 48);
	return (str);
}
