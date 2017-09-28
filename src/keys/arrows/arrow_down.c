/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/21 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						arrow_down(t_shell *shell)
{
	t_down				d;

	d.tmp = shell->list;
	d.i = 1;
	d.mod = 0;
	d.len = ft_list_len(shell->list);
	while (d.tmp && d.tmp->cursor == FALSE)
	{
		d.mod = d.i++ % shell->wpr;
		d.tmp = d.tmp->next;
	}
	d.tmp->cursor = FALSE;
	d.found = FALSE;
	arrow_down_bis(&d, shell);
	d.tmp2 = shell->list;
	d.i = 0;
	if (d.tmp == NULL && !d.found)
		arrow_down_ter(&d, shell);
}

void						arrow_down_bis(t_down *d, t_shell *shell)
{
	while (d->tmp && !d->found)
	{
		if (d->mod == 0 && d->i == 0)
			d->i++;
		else if (d->mod == d->i++ % shell->wpr && d->i != 0)
		{
			d->found = TRUE;
			if (d->tmp->next)
			{
				d->tmp = d->tmp->next;
				d->tmp->cursor = TRUE;
			}
			else
			{
				d->found = FALSE;
				d->tmp = d->tmp->next;
			}
		}
		else
			d->tmp = d->tmp->next;
	}
}

void						arrow_down_ter(t_down *d, t_shell *shell)
{
	while (d->tmp2 && !d->found)
	{
		if (ft_strcmp(d->tmp2->name, shell->list->name) == 0
			&& d->i == 0 && d->mod == shell->wpr - 1 % shell->wpr)
		{
			d->found = TRUE;
			d->tmp2->cursor = TRUE;
		}
		if (d->mod == d->i++ % shell->wpr)
		{
			if (d->i == d->len)
			{
				d->i = 0;
				d->tmp2 = shell->list;
				d->tmp2->cursor = TRUE;
				d->found = TRUE;
			}
			else
			{
			d->found = TRUE;
			if (d->tmp2->next)
				d->tmp2 = d->tmp2->next;
			d->tmp2->cursor = TRUE;
			}
		}
		else
				d->tmp2 = d->tmp2->next;
	}
}
