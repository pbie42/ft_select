/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 14:30:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						add_to_deleted(t_shell *shell, t_params *del)
{
	t_params				*tmp;

	tmp = shell->deleted;
	del->cursor = FALSE;
	if (!tmp)
	{
		shell->deleted = del;
		shell->deleted->d_next = NULL;
		shell->deleted->d_prev = NULL;
	}
	else
	{
		while (tmp->d_next)
			tmp = tmp->d_next;
		tmp->d_next = del;
		tmp->d_next->d_prev = tmp;
		tmp->d_next->d_next = NULL;
	}
}

void						delete_key(t_shell *shell)
{
	t_params				*tmp;
	t_bool					deleted;

	deleted = FALSE;
	tmp = shell->list;
	while (tmp && deleted == FALSE)
	{
		if (tmp->cursor == TRUE)
		{
			if (tmp->prev)
				tmp->prev->cursor = TRUE;
			else if (tmp->next)
				tmp->next->cursor = TRUE;
			else
				handle_exit(1);
			add_to_deleted(shell, tmp);
			ft_list_remove(shell, tmp);
			deleted = TRUE;
		}
		tmp = tmp->next;
	}
}
