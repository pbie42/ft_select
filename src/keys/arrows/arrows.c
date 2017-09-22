/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						arrow_right(t_shell *shell)
{
	t_params				*tmp;

	tmp = shell->list;
	while (tmp && tmp->cursor == FALSE)
		tmp = tmp->next;
	tmp->cursor = FALSE;
	if (tmp->next)
		tmp->next->cursor = TRUE;
	else
		shell->list->cursor = TRUE;
}

void						arrow_left(t_shell *shell)
{
	t_params				*tmp;
	t_params				*tmp2;
	
	tmp = shell->list;
	tmp2 = shell->list;
	while (tmp && tmp->cursor == FALSE)
	tmp = tmp->next;
	tmp->cursor = FALSE;
	if (tmp->prev)
	tmp->prev->cursor = TRUE;
	else
	{
		while (tmp2->next)
		tmp2 = tmp2->next;
		tmp2->cursor = TRUE;
	}
}

void						arrows(char *buf, t_shell *shell)
{
	t_shell				*shell2;

	shell2 = shell;
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
		arrow_up(shell);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
		arrow_down(shell);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
		arrow_left(shell);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
		arrow_right(shell);
	else if (buf[0] == 4)
	{
		printf("Ctlr+d, on quitte !\n");
		return ;
	}
}