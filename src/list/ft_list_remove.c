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

void						ft_list_remove(t_shell *shell, t_params *del)
{
	t_params				*tmp;
	t_params				*new_head;

	tmp = shell->list;
	while (tmp)
	{
		if (ft_strcmp(shell->list->name, del->name) == 0)
		{
			new_head = shell->list->next;
			new_head->prev = NULL;
			free_list_item(shell->list);
			shell->list = new_head;
			return ;
		}
		else if (ft_strcmp(tmp->name, del->name) == 0 && tmp->prev)
		{
			if (tmp->next)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			else
				tmp->prev->next = NULL;
			free_list_item(del);
			return ;
		}
		else
			tmp = tmp->next;
	}
}