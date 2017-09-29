/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						free_list_item(t_params *del)
{
	free(del->name);
	free(del);
}

void						prev_next(t_params *tmp)
{
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
}

void						ft_list_remove(t_shell *shell, t_params *del)
{
	t_remove				r;

	r.tmp = shell->list;
	while (r.tmp)
	{
		if (ft_strcmp(shell->list->name, del->name) == 0)
		{
			r.new_head = shell->list->next;
			r.new_head->prev = NULL;
			free_list_item(shell->list);
			shell->list = r.new_head;
			return ;
		}
		else if (ft_strcmp(r.tmp->name, del->name) == 0 && r.tmp->prev)
		{
			if (r.tmp->next)
				prev_next(r.tmp);
			else
				r.tmp->prev->next = NULL;
			free_list_item(del);
			return ;
		}
		else
			r.tmp = r.tmp->next;
	}
}
