/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:48:54 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/02/13 14:48:54 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_mylog(long long int num)
{
	int i;
	int	j;

	i = 1;
	j = 0;
	if (num == -9223372036854775807)
		return (20);
	if (num < 0)
	{
		j = 1;
		num = (num * -1);
	}
	while (num >= 10)
	{
		i++;
		num = (num / 10);
	}
	return (i + j);
}

int	ft_mylog_unsigned(unsigned long long int num)
{
	int i;

	i = 1;
	while (num >= 10)
	{
		i++;
		num = (num / 10);
	}
	return (i);
}

int	ft_mylog_hex(unsigned int num)
{
	int i;

	i = 1;
	while (num >= 16)
	{
		i++;
		num = (num / 16);
	}
	return (i);
}
