/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:42:17 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/08 14:42:17 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_color_up(t_color *colors)
{
	if (colors->selected == 1)
	{
		colors->selected = 0;
		while (colors->next)
			colors = colors->next;
		colors->selected = 1;
	}
	else
	{
		while (colors->next->selected == 0)
			colors = colors->next;
		colors->selected = 1;
		colors = colors->next;
		colors->selected = 0;
	}
}

static void	ft_color_down(t_color *colors)
{
	if (colors->next->next->next->selected == 1)
	{
		colors->next->next->next->selected = 0;
		colors->selected = 1;
	}
	else
	{
		while (colors->selected == 0)
			colors = colors->next;
		colors->selected = 0;
		colors->next->selected = 1;
	}
}

static int	ft_color_read(t_color *colors, int pipe)
{
	char	*line;

	line = ft_memalloc(1024);
	read(pipe, line, 15);
	if (*line == 10)
	{
		free(line);
		return (0);
	}
	if (line[0] == '\033' && line[2] == 65)
		ft_color_up(colors);
	if (line[0] == '\033' && line[2] == 66)
		ft_color_down(colors);
	free(line);
	return (1);
}

static void	ft_color_menu(t_cap caps, t_color *colors)
{
	int i;

	i = 2;
	GOTO(4, 0);
	ft_printe("%s%sCOLOR", ft_menu(), caps.mr);
	GOTO(4, 1);
	ft_printe("┏━━━━━━━━━━━━━━━━━━━━┓");
	GOTO(4, 6);
	ft_printe("┗━━━━━━━━━━━━━━━━━━━━┛");
	while (colors)
	{
		GOTO(4, i);
		if (colors->selected == 0)
			ft_printe("┃  %s  ┃", colors->colors);
		else
			ft_printe("┃  %s%s%s%s  ┃", caps.me, ft_menu(), colors->colors,
					caps.mr);
		colors = colors->next;
		i++;
	}
	ft_printe("%s%s", DEF_COL, caps.me);
}

void		ft_colors(t_cap caps, t_color *colors, int pipe)
{
	struct winsize	win;
	t_color			*head;

	head = colors;
	ioctl(0, TIOCGWINSZ, &win);
	if (win.ws_row >= 8 && win.ws_col >= 30)
	{
		ft_printe(caps.vi);
		ft_color_menu(caps, colors);
		while (win.ws_col >= 30 && win.ws_row >= 8 && ft_color_read(head, pipe))
			ft_color_menu(caps, colors);
		if (head->selected == 1)
			g_color = 1;
		else if (head->next->selected == 1)
			g_color = 2;
		else if (head->next->next->selected == 1)
			g_color = 3;
		else
			g_color = 4;
		ft_init_display(caps);
	}
}
