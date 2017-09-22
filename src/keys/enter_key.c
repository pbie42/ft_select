/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						enter_key(t_shell *shell)
{
	t_params				*tmp;

	shell_env_off(shell);
	tmp = shell->list;
	while (tmp->next)
	{
		if (tmp->selected)
		{
			ft_putstr_fd(tmp->name, 1);
			ft_putstr_fd(" ", 1);
		}
		tmp = tmp->next;
	}
	ft_putstr_fd(tmp->name, 1);
	exit(1);

}