/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/30 19:03:16 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						search_key(t_shell *shell, char buf)
{
	t_params				*tmp;
	t_params				*tmp2;
	t_bool					found;

	tmp = shell->list;
	tmp2 = shell->list;
	found = FALSE;
	while (tmp && !found)
	{
		if (tmp->name[0] == buf)
			found = TRUE;
		else
			tmp = tmp->next;
	}
	while (tmp2 && found)
	{
		if (ft_strcmp(tmp->name, tmp2->name) == 0)
			tmp2->cursor = TRUE;
		else
			tmp2->cursor = FALSE;
		tmp2 = tmp2->next;
	}
}
