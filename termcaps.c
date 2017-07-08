/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:16:42 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/01 14:16:42 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_termios(void)
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	tcgetattr(STDIN_FILENO, &g_sig.term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	ft_allocate_capabilities(t_cap *caps)
{
	caps->cl = ft_memalloc(24);
	caps->ce = ft_memalloc(24);
	caps->us = ft_memalloc(24);
	caps->ue = ft_memalloc(24);
	caps->me = ft_memalloc(24);
	caps->mr = ft_memalloc(24);
	caps->vi = ft_memalloc(24);
	caps->ve = ft_memalloc(24);
	caps->kr = ft_memalloc(24);
	caps->kl = ft_memalloc(24);
	caps->cm = ft_memalloc(24);
	caps->te = ft_memalloc(24);
	caps->ti = ft_memalloc(24);
}

void		ft_free_capabilities(t_cap *caps)
{
	free(caps->cl);
	free(caps->ce);
	free(caps->us);
	free(caps->ue);
	free(caps->me);
	free(caps->mr);
	free(caps->vi);
	free(caps->ve);
	free(caps->kr);
	free(caps->kl);
	free(caps->cm);
	free(caps->ti);
	free(caps->te);
}

void		ft_capabilities(t_cap *caps)
{
	char *buffer;

	buffer = ft_memalloc(2048);
	ft_allocate_capabilities(caps);
	if ((tgetent(buffer, getenv("TERM")) == -1))
	{
		free(buffer);
		ft_printe("%s terminal type invalid or TERM does not exist\n", CE);
		ft_free_capabilities(caps);
		exit(0);
	}
	caps->cm = tgetstr("cm", &caps->cm);
	caps->cl = tgetstr("cl", &caps->cl);
	caps->ce = tgetstr("ce", &caps->ce);
	caps->us = tgetstr("us", &caps->us);
	caps->ue = tgetstr("ue", &caps->ue);
	caps->me = tgetstr("me", &caps->me);
	caps->mr = tgetstr("mr", &caps->mr);
	caps->vi = tgetstr("vi", &caps->vi);
	caps->ve = tgetstr("ve", &caps->ve);
	caps->kl = tgetstr("kl", &caps->kl);
	caps->kr = tgetstr("kr", &caps->kr);
	caps->ti = tgetstr("ti", &caps->ti);
	caps->te = tgetstr("te", &caps->te);

}
