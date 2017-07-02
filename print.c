/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:39:54 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/01 14:39:54 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_print_arg(t_cap caps, t_args link, size_t width)
{
	int	i;

	i = 0;
	ft_printe("%s\033[40m\033[33m", caps.me);
	if (link.cursor == 1)
		ft_printe("%s", caps.us);
	if (link.selected == 1)
		ft_printe("%s", caps.mr);
	ft_printe("%s%s\033[40m\033[33m", link.arg, caps.me);
	while (i++ + ft_strlen(link.arg) < width)
		ft_printe(" ");
	ft_printe("\033[39m\033[49m");
}

static void	ft_position(t_args *head, struct winsize win, size_t width)
{
	int row;
	int col;

	row = 1;
	col = 1;
	while (head->next->head == 0)
	{
		while (head->next->head == 0 && (col * width) < win.ws_xpixel)
		{
			head->x = col;
			head->y = row;
			head = head->next;
			col++;
		}
		if (col * width >= win.ws_xpixel)
		{
			row++;
			col = 1;
		}
	}
	head->x = col;
	head->y = row;
}

static void	ft_start(t_args **head, struct winsize win, int *start)
{
	t_args	*temp;

	temp = *head;
	*start = 1;
	ft_cursor(&temp);
	if (temp->y > win.ws_ypixel)
	{
		*start = ((temp->y - win.ws_ypixel) + 1);
		while ((*head)->y != *start)
			*head = (*head)->next;
	}
}

static void	ft_layout(t_cap caps, t_args *args, int row, int start)
{
	struct winsize	win;
	size_t			width;

	ft_width(args, &width);
	ft_set_win(&win);
	if (width >= win.ws_xpixel || win.ws_row < 5)
		return ;
	ft_position(args, win, width);
	ft_start(&args, win, &start);
	row = start;
	if (args->next == args)
		ft_print_arg(caps, *args, width);
	while (args->next->head == 0 && row - start < win.ws_ypixel)
	{
		while (args->next->head == 0 && args->y == row)
		{
			ft_print_arg(caps, *args, width);
			args = args->next;
		}
		row++;
		if (args->y == row)
			tputs(tgoto(caps.cm, 8, (((row - start) + 2))), 1, ft_fputchar);
		if (args->next->head == 1 && args->y - start < win.ws_ypixel)
			ft_print_arg(caps, *args, width);
	}
}

void		ft_print_handler(t_cap caps, t_args *args)
{
	g_sig.args = args;
	tputs(tgoto(caps.cm, 8, 2), 1, ft_fputchar);
	ft_head(&args);
	ft_layout(caps, args, 0, 0);
}
