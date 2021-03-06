/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					space_key(t_shell *shell)
{
	t_params			*tmp;

	tmp = shell->list;
	free(shell->search);
	shell->search = NULL;
	while (tmp)
	{
		if (tmp->cursor == TRUE)
			tmp->selected = !tmp->selected;
		tmp = tmp->next;
	}
}
