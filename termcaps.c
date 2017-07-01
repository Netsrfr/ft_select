/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:16:42 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/01 14:16:42 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_termios()
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	tcgetattr(STDIN_FILENO, &g_sig.term);
	term.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
//	term.c_cc[VMIN] = 0;
}

static void	ft_allocate_capabilities(t_cap *caps)
{
	caps->cl = ft_memalloc(16);
	caps->ce = ft_memalloc(16);
	caps->us = ft_memalloc(16);
	caps->me = ft_memalloc(16);
	caps->mr = ft_memalloc(16);
	caps->vi = ft_memalloc(16);
	caps->ve = ft_memalloc(16);
	caps->kr = ft_memalloc(16);
	caps->kl = ft_memalloc(16);
	caps->cm = ft_memalloc(16);


}

void		ft_capabilities(t_cap *caps)
{
	char *buffer = ft_memalloc(2048);
	ft_allocate_capabilities(caps);
	if((tgetent(buffer, getenv("TERM")) == -1))
	{
		free(buffer);
		ft_printe("ft_select: error: terminal type invalid or TERM does not exist\n");
		exit(0);
	}
	caps->cm = tgetstr("cm", &caps->cm);
	caps->cl = tgetstr("cl", &caps->cl);
	caps->ce = tgetstr("ce", &caps->ce);
	caps->us = tgetstr("us", &caps->us);
	caps->me = tgetstr("me", &caps->me);
	caps->mr = tgetstr("mr", &caps->mr);
	caps->vi = tgetstr("vi", &caps->vi);
	caps->ve = tgetstr("ve", &caps->ve);
	caps->kl = tgetstr("kl", &caps->kl);
	caps->kr = tgetstr("kr", &caps->kr);
}

