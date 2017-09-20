/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_exit(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = get_shell();
	shell_env_off(shell);
	exit(0);
}

void	handle_sigwinch(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = get_shell();
	updateshell(shell);
	tputs(tgetstr("cl", NULL), 1, putintc);
	view(shell);
}

void		sig_handler(int sig)
{
	if (sig == SIGWINCH)
		handle_sigwinch(0);
	else if (sig == SIGINT)
		handle_exit(0);
	else if (sig == SIGQUIT)
		handle_exit(0);
	else if (sig == SIGKILL)
		handle_exit(0);
	else if (sig == SIGTERM)
		handle_exit(0);
}

void		ft_signal(void)
{
	int		i;

	i = 0;
	while (i < 33)
	{
		signal(i, sig_handler);
		i++;
	}
}