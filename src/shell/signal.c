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

void		sig_handler(int sig)
{
	if (sig == SIGWINCH)
		handle_sigwinch(0);
	else if (sig == SIGTSTP)
		handle_pause(0);
	else if (sig == SIGCONT)
		handle_resume(0);
	else if (sig == SIGINT)
		handle_exit(0);
	else if (sig == SIGQUIT)
		handle_exit(0);
	else if (sig == SIGKILL)
		handle_exit(0);
	else if (sig == SIGTERM)
		handle_exit(0);
	else if (sig == SIGFPE)
		handle_fpe(0);
	else
	{
		
	}
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