/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						handle_exit(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = get_shell();
	shell_env_off(shell);
	ft_list_free(shell->list);
	ft_deleted_free(shell->deleted);
	if (shell->search)
		free(shell->search);
	exit(0);
}

void						handle_sigwinch(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = get_shell();
	updateshell(shell);
	tputs(tgetstr("cl", NULL), 1, putintc);
	view(shell);
}

void						handle_pause(int sig)
{
	char	buf[2];
	t_shell	*shell;

	(void)sig;
	shell = get_shell();
	buf[0] = shell->tios_old->c_cc[VSUSP];
	buf[1] = 0;
	shell_env_off(shell);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, buf);
	ft_putstr_fd(" ", 0);
}

void						handle_resume(int sig)
{
	t_shell	*shell;

	(void)sig;
	signal(SIGTSTP, handle_pause);
	signal(SIGCONT, handle_resume);
	shell = get_shell();
	shell_env_on(shell);
	tputs(tgetstr("cl", NULL), 1, putintc);
	view(shell);
}

void						handle_fpe(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = get_shell();
	tputs(tgetstr("cl", NULL), 1, putintc);
	if (shell->sizemax + 4 > shell->wsz->ws_col)
		ft_putendl_fd("TOO SMALL!!", 0);
	else
		view(shell);
}
