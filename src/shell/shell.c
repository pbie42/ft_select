/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 15:02:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_shell				*get_shell(void)
{
	static t_shell *save = NULL;

	if (save == NULL)
		save = new_shell();
	updateshell(save);
	return (save);
}

void				updateshell(t_shell *shell)
{
	struct winsize w;

	if (ioctl(0, TIOCGWINSZ, &w) == 0)
		ft_putendl("\0");
	shell->wsz->ws_col = w.ws_col;
	shell->wsz->ws_row = w.ws_row;
}

t_shell				*new_shell(void)
{
	t_shell			*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->list = NULL;
	shell->deleted = NULL;
	shell->tios_old = (struct termios*)malloc(sizeof(struct termios));
	shell->tios = (struct termios*)malloc(sizeof(struct termios));
	shell->wsz = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, shell->wsz);
	if (tcgetattr(0, shell->tios_old) == -1)
		return (NULL);
	tcgetattr(0, shell->tios);
	shell->tios->c_lflag &= ~(ICANON);
	shell->tios->c_lflag &= ~(ECHO);
	shell_env_on(shell);
	return (shell);
}
