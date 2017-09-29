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
			ft_list_remove(shell, tmp);
			deleted = TRUE;
		}
		tmp = tmp->next;
	}
}
