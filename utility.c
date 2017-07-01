/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 09:25:23 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/01 09:25:23 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_cursor(t_args **args)
{
	while ((*args)->cursor == 0)
		(*args) = (*args)->next;
}

void	ft_head(t_args **args)
{
	while ((*args)->head == 0)
		(*args) = (*args)->next;
}
