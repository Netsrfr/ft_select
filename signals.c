/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 11:42:32 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/02 11:42:32 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_interrupt(int sig)
{
	if (sig == SIGINT)
	{
		ft_printe("%s%s%s", g_sig.caps.me, g_sig.caps.ve, g_sig.caps.te);
		kill(0, SIGTERM);
	}
}

static void	ft_sigtstp(int sig)
{
	if (sig == SIGTSTP)
	{
		ft_printe("%s%s%s", g_sig.caps.ve, g_sig.caps.me, g_sig.caps.te);
		kill(0, SIGTSTP);
	}
}

static void	ft_sigwinch(int sig)
{
	if (sig == SIGWINCH)
	{
		ft_init_display(g_sig.caps);
		ft_print_handler(g_sig.caps, g_sig.args);
	}
}

static void	ft_sigcont(int sig)
{
	if (sig == SIGCONT)
	{
		ft_sigaction();
		ft_termios();
		ft_printe(g_sig.caps.ti);
		ft_init_display(g_sig.caps);
		ft_print_handler(g_sig.caps, g_sig.args);
	}
}

void		ft_sigaction(void)
{
	struct sigaction sigtstp;
	struct sigaction sigcont;
	struct sigaction sigint;

	signal(SIGWINCH, ft_sigwinch);
	sigtstp.sa_handler = ft_sigtstp;
	sigtstp.sa_flags = SA_RESETHAND;
	sigtstp.sa_mask = SIGTSTP;
	sigaction(SIGTSTP, &sigtstp, NULL);
	sigcont.sa_handler = ft_sigcont;
	sigcont.sa_flags = SA_NODEFER;
	sigcont.sa_mask = SIGCONT;
	sigaction(SIGCONT, &sigcont, NULL);
	sigint.sa_handler = ft_interrupt;
	sigint.sa_mask = SIGINT;
	sigaction(SIGINT, &sigint, NULL);
}
