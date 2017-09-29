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

void						undo_key(t_shell *shell)
{
	t_params				*tmp;
	t_params				*tmp2;
	t_params				*undo;

	ft_putendl("IN HERE!!!!!!!!!!!!");
	tmp = shell->deleted;
	while (tmp->d_next)
		tmp = tmp->d_next;
	ft_putendl(tmp->name);
	ft_putendl(tmp->next->name);
	if (tmp->d_prev)
		tmp->d_prev->d_next = NULL;
	tmp->d_prev = NULL;
	undo = tmp;
	tmp2 = shell->list;
	ft_putendl("goign to while");
	while (tmp2)
	{
		ft_putendl("while");
		if (ft_strcmp(undo->next->name, tmp2->name) == 0)
		{
			ft_putendl("matched!");
			tmp2->prev->next = undo;
			undo->next->prev = undo;
		}
		tmp2 = tmp2->next;
	}
}
