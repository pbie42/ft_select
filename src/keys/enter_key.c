/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						enter_key_bis(t_enter *e)
{
	while (e->tmp2->next)
	{
		if (e->tmp2->selected)
		{
			ft_putstr_fd(e->tmp2->name, 1);
			if (e->i < e->amnt_selected - 1)
			{
				ft_putstr_fd(" ", 1);
			}
			e->i++;
		}
		e->tmp2 = e->tmp2->next;
	}
}

void						enter_key(t_shell *shell)
{
	t_enter				e;

	free(shell->search);
	shell->search = NULL;
	shell_env_off(shell);
	e.amnt_selected = 0;
	e.i = 0;
	e.tmp = shell->list;
	while (e.tmp)
	{
		if (e.tmp->selected)
			e.amnt_selected++;
		e.tmp = e.tmp->next;
	}
	e.tmp2 = shell->list;
	enter_key_bis(&e);
	if (e.tmp2->selected)
		ft_putstr_fd(e.tmp2->name, 1);
	ft_shell_free(shell);
	exit(1);
}
