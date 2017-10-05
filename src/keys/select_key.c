/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/30 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						select_key(t_shell *shell)
{
	t_params				*tmp;

	free(shell->search);
	shell->search = NULL;
	tmp = shell->list;
	while (tmp)
	{
		tmp->selected = TRUE;
		tmp = tmp->next;
	}
}

void						deselect_key(t_shell *shell)
{
	t_params				*tmp;

	free(shell->search);
	shell->search = NULL;
	tmp = shell->list;
	while (tmp)
	{
		tmp->selected = FALSE;
		tmp = tmp->next;
	}
}
