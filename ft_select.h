/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:14:06 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/06/19 16:14:06 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/ft_printe/ft_printe.h"
# include <termcap.h>
# include <sys/termios.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define CE "ft_select: \x1b[31merror:\x1b[39m"
# define GOTO(x, y) (tputs(tgoto(caps.cm, x, y), 1, ft_fputchar))
# define DEF_COL "\033[39m\033[49m"
# define C1 "\033[40m\033[38;5;11m"
# define M1 "\033[44m\033[37m"
# define C2 M1
# define M2 "\033[40m\033[37m"
# define C3 "\033[40m\033[37m"
# define M3 M1
# define C4 "\033[48;5;8m\033[37m"
# define M4 "\033[48;5;7m\033[30m"
# define CX "\033[48;5;168m\033[30m"

typedef struct		s_args
{
	char			*arg;
	int				head;
	int				cursor;
	int				selected;
	int				x;
	int				y;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

typedef struct		s_cap
{
	char			*cm;
	char			*cl;
	char			*ce;
	char			*us;
	char			*ue;
	char			*mr;
	char			*me;
	char			*vi;
	char			*ve;
	char			*kl;
	char			*kr;
	char			*ti;
	char			*te;
}					t_cap;

typedef struct		s_sig
{
	t_cap			caps;
	t_args			*args;
	struct termios	term;
}					t_sig;

typedef struct		s_color
{
	int				selected;
	char			*colors;
	struct s_color	*next;
}					t_color;

t_sig				g_sig;
t_color				*g_colors;
int					g_color;

/*
** arrows.c
*/
void				ft_arrows(char line, t_cap caps, t_args *args);

/*
** bonus.c
*/
int					ft_confirm(struct winsize win, t_cap caps);
char				*ft_color(void);
char				*ft_menu(void);

/*
** colors.c
*/
void				ft_colors(t_cap caps, t_color *colors, int pipe);
void				ft_init_colors(t_color **color1);

/*
** display.c
*/
void				ft_set_win(struct winsize *w);
void				ft_init_display(t_cap caps);

/*
** keys.c
*/
void				ft_keys(char *line, t_cap caps, t_args **args);
void				ft_exit(t_cap caps, t_args *args, int caller);

/*
** print.c
*/
void				ft_print_handler(t_cap caps, t_args *args);

/*
** signals.c
*/
void				ft_sigaction(void);

/*
** termcaps.c
*/
void				ft_free_capabilities(t_cap *caps);
void				ft_capabilities(t_cap *caps);
void				ft_termios();

/*
** utility.c
*/
void				ft_width(t_args *head, size_t *width);
void				ft_free_args(t_args **args);
void				ft_cursor(t_args **args);
void				ft_head(t_args **args);
void				ft_free_colors(void);
#endif
