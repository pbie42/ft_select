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

void						undo_key(t_shell *shell)
{
	t_params				*tmp;
	t_params				*tmp2;
	t_params				*undo;

	tmp = shell->deleted;
	if (!tmp)
		return ;
	while (tmp->d_next)
		tmp = tmp->d_next;
	if (tmp->d_prev)
		tmp->d_prev->d_next = NULL;
	undo = tmp;
	tmp2 = shell->list;
	while (tmp2->next)
	{
		if (undo->next && ft_strcmp(undo->next->name, tmp2->name) == 0)
		{
			if (tmp2->prev)
			{
				check_deleted(undo, shell);
				tmp2->prev->next = undo;
				tmp2->prev = undo;
				return ;
			}
			else
			{
				check_deleted(undo, shell);
				tmp2->prev = undo;
				shell->list = undo;
				return ;
			}
		}
		// need to do else
		tmp2 = tmp2->next;
	}
	if (!undo->next)
	{
		check_deleted(undo, shell);
		tmp2->next = undo;
	}
	if (!tmp2->next)
	{
		tmp2->prev = undo;
		shell->list = undo;
	}
}
