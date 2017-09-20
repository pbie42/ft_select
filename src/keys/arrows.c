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

void						arrow_down(t_shell *shell)
{
	t_params				*tmp;
	t_params				*tmp2;
	int					mod;
	int					i;
	t_bool				found;

	tmp = shell->list;
	i = 0;
	mod = 0;
	while (tmp && tmp->cursor == FALSE)
	{
		mod = i++ % shell->wpr;
		tmp = tmp->next;
	}
	ft_putstr("i is");
	ft_putnbr(i);
	ft_putchar('\n');
	tmp->cursor = FALSE;
	found = FALSE;
	while (tmp && !found)
	{
		if (mod == 0 && i == 0)
			i++;
		else if (mod == i++ % shell->wpr)
		{
			found = TRUE;
			tmp = tmp->next;
			tmp->cursor = TRUE;
		}
		else
			tmp = tmp->next;
	}
	tmp2 = shell->list;
	i = 0;
	if (tmp == NULL && !found)
		while (tmp2 && !found)
		{
			if (mod == i++ % shell->wpr)
			{
				found = TRUE;
				tmp2 = tmp2->next;
				tmp2->cursor = TRUE;
			}
			else
				tmp2 = tmp2->next;
		}
	if (found == FALSE)
		ft_putendl("not found");
	ft_putendl("end");
}