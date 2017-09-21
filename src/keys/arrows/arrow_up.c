/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/21 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						arrow_up(t_shell *shell)
{
	t_up					u;

	u.i = 0;
	u.mod = 0;
	u.end = ft_list_end(shell->list);
	u.tmp = shell->list;
	arrow_up_setup(&u, shell);
	u.tmp->cursor = FALSE;
	u.len = ft_list_len(shell->list);
	u.found = FALSE;
	arrow_up_bis(&u, shell);
	u.i = u.len;
	u.tmp3 = u.end;
	arrow_up_ter(&u, shell);
}

void						arrow_up_setup(t_up *u, t_shell *shell)
{
	u->setup_i = FALSE;
	while (u->tmp && u->tmp->cursor == FALSE)
	{
		u->setup_i = TRUE;
		u->i++;
		u->tmp = u->tmp->next;
	}
	if (u->setup_i)
	{
		u->mod = u->i-- % shell->wpr;
		u->tmp2 = u->tmp->prev;
	}
	else
		u->tmp2 = u->end;
}

void						arrow_up_bis(t_up *u, t_shell *shell)
{
	while (u->tmp2 && !u->found)
	{
		if (u->mod == 0 && u->i == 0)
			u->i = u->len;
		if (u->mod == u->i % shell->wpr)
		{
			if (u->tmp2->prev)
			{
				u->found = TRUE;
				u->tmp2->cursor = TRUE;
				u->tmp2 = u->tmp2->prev;
			}
			else
			{
				u->found = TRUE;
				u->tmp2->cursor = TRUE;
			}
		}
		else
		{
			u->i--;
			u->tmp2 = u->tmp2->prev;
		}
	}
}

void						arrow_up_ter(t_up *u, t_shell *shell)
{
	if (u->tmp2 == NULL && !u->found)
		while (u->tmp3 && !u->found)
		{
			if (u->mod == 0 && u->i == 0)
				u->i = u->len;
			if (u->mod == u->i % shell->wpr)
			{
				if (u->tmp3->prev)
				{
					u->found = TRUE;
					u->tmp3->cursor = TRUE;
					u->tmp3 = u->tmp3->prev;
				}
				else
				{
					u->found = FALSE;
					u->tmp3 = u->tmp3->prev;
				}
			}
			else
			{
				u->i--;
				u->tmp3 = u->tmp3->prev;
			}
		}
}
