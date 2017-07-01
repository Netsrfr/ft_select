/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:19:16 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/01 14:19:16 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_set_win(struct winsize *win)
{
	ioctl(0, TIOCGWINSZ, win);
	win->ws_xpixel = (unsigned short)(win->ws_col > 11 ? (win->ws_col - 11) : 0);
	win->ws_ypixel = (unsigned short)(win->ws_col > 4 ? (win->ws_row - 4) : 0);
}

static void	ft_header(struct winsize win, t_cap caps)
{
	tputs(tgoto(caps.cm, 0, 0), 1, ft_fputchar);
	ft_printe("%s\033[40m%s\033[44m\033[37m", caps.me, caps.cl);
	tputs(tgoto(caps.cm, 0, 0), 1, ft_fputchar);
	ft_printe("%s\033[44m%s\033[37m", caps.me, caps.ce);
	if (win.ws_col >= 9)
	{
		tputs(tgoto(caps.cm, (win.ws_col / 2 - 4), 0), 1, ft_fputchar);
		ft_printe("ft_select");
	}
}

static void	ft_footer(struct winsize win, t_cap caps)
{
	tputs(tgoto(caps.cm, 0, win.ws_row), 1, ft_fputchar);
	ft_printe("%s\033[44m%s\033[37m", caps.me, caps.ce);
	tputs(tgoto(caps.cm, 4, win.ws_row), 1, ft_fputchar);
	if (win.ws_col >= 18)
	{
		tputs(tgoto(caps.cm, win.ws_col - 14, win.ws_row), 1, ft_fputchar);
		ft_printe("ESC = EXIT");
	}
	if (win.ws_col >= 56)
	{
		tputs(tgoto(caps.cm, 4, win.ws_row), 1, ft_fputchar);
		ft_printe("NAVIGATION = UP, DOWN, LEFT, RIGHT");
	}
	if (win.ws_col >= 94)
	{
		tputs(tgoto(caps.cm, ((win.ws_col - 90) / 3) + 41, win.ws_row), 1, ft_fputchar);
		ft_printe("SELECT = SPACE");
		tputs(tgoto(caps.cm, ((win.ws_col - 90) / 3) * 2 + 59, win.ws_row), 1, ft_fputchar);
		ft_printe("RETURN = CONFIRM");

	}
}

void		ft_init_display(t_cap caps)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	ft_header(win, caps);
	ft_footer(win, caps);
	ft_printe("%s%s\033[40m\033[33m", caps.me, caps.vi);
}
