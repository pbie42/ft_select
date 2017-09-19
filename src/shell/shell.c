/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						updateshell(t_shell *shell)
{
	struct winsize w;

	ft_putendl("before ioctl");
	if (ioctl(0, TIOCGWINSZ, &w) == 0)
		ft_putendl("NO error bruh bruh");
	ft_putendl("after ioctl");
	shell->wsz.ws_col = w.ws_col;
	shell->wsz.ws_row = w.ws_row;
	ft_putendl("after change");
}

void				new_shell(t_shell *shell)
{
	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->list = NULL;
	shell->tios_old = (struct termios*)malloc(sizeof(struct termios));
	shell->tios = (struct termios*)malloc(sizeof(struct termios));
	shell->wsz = *(struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, shell->wsz);
	if (tcgetattr(0, shell->tios_old) == -1)
		return ;
	tcgetattr(0, shell->tios);
	shell->tios->c_lflag &= ~(ICANON);
	shell->tios->c_lflag &= ~(ECHO);
	tcsetattr(0, TCSADRAIN, shell->tios);
}