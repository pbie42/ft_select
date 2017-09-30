/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						check_deleted(t_params *undo, t_shell *shell)
{
	if (!undo->d_prev && undo->d_next)
	{
		undo->d_next->d_prev = NULL;
		shell->deleted = undo->d_next;
		undo->d_next = NULL;
	}
	else if (undo->d_prev && !undo->d_next)
	{
		undo->d_prev->d_next = NULL;
		undo->d_prev = NULL;
	}
	else if (!undo->d_prev && !undo->d_next)
		shell->deleted = NULL;
}

void						undo_key_bis(t_undo *u, t_shell *shell)
{
	while (u->tmp2->next)
	{
		if (u->undo->next
		&& ft_strcmp(u->undo->next->name, u->tmp2->name) == 0)
		{
			if (u->tmp2->prev)
			{
				check_deleted(u->undo, shell);
				u->tmp2->prev->next = u->undo;
				u->tmp2->prev = u->undo;
				return ;
			}
			else
			{
				check_deleted(u->undo, shell);
				u->tmp2->prev = u->undo;
				shell->list = u->undo;
				return ;
			}
		}
		u->tmp2 = u->tmp2->next;
	}
}

void						undo_key(t_shell *shell)
{
	t_undo				u;

	u.tmp = shell->deleted;
	if (!u.tmp)
		return ;
	while (u.tmp->d_next)
		u.tmp = u.tmp->d_next;
	if (u.tmp->d_prev)
		u.tmp->d_prev->d_next = NULL;
	u.undo = u.tmp;
	u.tmp2 = shell->list;
	undo_key_bis(&u, shell);
	if (!u.undo->next)
	{
		check_deleted(u.undo, shell);
		u.tmp2->next = u.undo;
	}
	if (!u.tmp2->next)
	{
		u.tmp2->prev = u.undo;
		shell->list = u.undo;
	}
}
