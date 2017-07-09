/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:21:38 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/08 16:21:38 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char		*ft_color(void)
{
	if (g_color == 1)
		return (C1);
	else if (g_color == 2)
		return (C2);
	else if (g_color == 3)
		return (C3);
	else
		return (C4);
}

char		*ft_menu(void)
{
	if (g_color == 1)
		return (M1);
	else if (g_color == 2)
		return (M2);
	else if (g_color == 3)
		return (M3);
	else
		return (M4);
}

static void	ft_confirmation_window(struct winsize win, t_cap caps)
{
	int	i;

	i = 1;
	GOTO(win.ws_xpixel - 18, win.ws_ypixel - 5);
	ft_printe("%s╔══════════════════════════════════╗", ft_menu());
	GOTO(win.ws_xpixel - 18, (win.ws_ypixel - 5) + i++);
	ft_printe("║ %s%s%s ║", CX, " ARE YOU SURE YOU WANT TO EXIT? ", ft_menu());
	while (i <= 6)
	{
		GOTO(win.ws_xpixel - 18, (win.ws_ypixel - 5) + i++);
		ft_printe("║ %s%*s%s ║", CX, 32, " ", ft_menu());
	}
	GOTO(win.ws_xpixel - 18, (win.ws_ypixel - 5) + i++);
	ft_printe("║ %s%s%s ║", CX, " ANY = SELECT   ENTER = CONFIRM ", ft_menu());
	GOTO(win.ws_xpixel - 18, (win.ws_ypixel - 5) + i);
	ft_printe("%s╚══════════════════════════════════╝", ft_menu());
	GOTO(win.ws_xpixel - 6, win.ws_ypixel - 1);
	ft_printe("%s%s YES  / %s NO ", caps.me, CX, caps.mr);
}

int			ft_confirm(struct winsize win, t_cap caps)
{
	char	*line;
	int		pipe;
	int		flag;

	flag = 1;
	line = ft_memalloc(1024);
	pipe = open("/dev/stdin", O_RDONLY);
	win.ws_ypixel = (unsigned short)(win.ws_row / 2);
	win.ws_xpixel = (unsigned short)(win.ws_col / 2);
	ft_confirmation_window(win, caps);
	while (read(pipe, line, 15))
	{
		GOTO(win.ws_xpixel - 6, win.ws_ypixel - 1);
		if (flag == 0)
			ft_printe("%s%s YES  / %s NO ", caps.me, CX, caps.mr);
		else
			ft_printe("%s%s YES %s%s /  NO ", CX, caps.mr, caps.me, CX);
		if (*line == 10)
			break ;
		flag = flag == 0 ? 1 : 0;
	}
	free(line);
	return (flag);
}
