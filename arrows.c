/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:08:10 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/06/30 13:08:10 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_right(t_cap caps, t_args *args)
{
	int	row;

	ft_cursor(&args);
	args->cursor = 0;
	row = args->y;
	args = args->next;
	while (args->y != row)
	{
		args = args->next;
	}
	args->cursor = 1;
	ft_print_handler(caps, args);
}

void	ft_left(t_cap caps, t_args *args)
{
	int	row;

	while (args->cursor == 0)
		args = args->next;
	args->cursor = 0;
	row = args->y;
	args = args->prev;
	while (args->y != row)
	{
		args = args->prev;
	}
	args->cursor = 1;
	ft_print_handler(caps, args);
}

void	ft_up(t_cap caps, t_args *args)
{
	int	col;

	while (args->cursor == 0)
		args = args->next;
	args->cursor = 0;
	col = args->x;
	args = args->prev;
	while (args->x != col)
	{
		args = args->prev;
	}
	args->cursor = 1;
	ft_print_handler(caps, args);
}

void	ft_down(t_cap caps, t_args *args)
{
	int	col;

	while (args->cursor == 0)
		args = args->next;
	args->cursor = 0;
	col = args->x;
	args = args->next;
	while (args->x != col)
	{
		args = args->next;
	}
	args->cursor = 1;
	ft_print_handler(caps, args);
}

void	ft_arrows(char line, t_cap caps, t_args *args)
{
	if (line == 65)
		ft_up(caps, args);
	if (line == 66)
		ft_down(caps, args);
	if (line == 67)
		ft_right(caps, args);
	if (line == 68)
		ft_left(caps, args);
}
