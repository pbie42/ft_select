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
	t_bool				setup_i;

	u.i = 0;
	u.mod = 0;
	u.len = 0;
	u.end = ft_list_end(shell->list);
	u.tmp = shell->list;
	setup_i = FALSE;
	ft_putendnbr("u.len is ", u.len);
	while (u.tmp && u.tmp->cursor == FALSE)
	{
		setup_i = TRUE;
		u.i++;
		u.tmp = u.tmp->next;
	}
	if (setup_i)
	{

		u.mod = u.i % shell->wpr;
		u.i--;
		ft_putendl("setup i");
		u.tmp2 = u.tmp->prev;
	}
	else
		u.tmp2 = u.end;
	u.tmp->cursor = FALSE;
	ft_putendl("before list len");
	u.len = ft_list_len(shell->list);
	ft_putendnbr("wpr is ", shell->wpr);
	ft_putendnbr("u.i is ", u.i);
	ft_putendnbr("u.mod is ", u.mod);
	ft_putendnbr("u.len is ", u.len);
	u.found = FALSE;
	// u.i = u.len;
	while (u.tmp2 && u.found == FALSE)
	{
		ft_putendl("while");
		ft_putendnbr("wpr WHILE is ", shell->wpr);
		ft_putendnbr("u.i WHILE is ", u.i);
		ft_putendnbr("u.mod WHILE is ", u.mod);
		if (u.mod == 0 && u.i == 0)
		{
			ft_putendl("HERE");
			u.i = u.len;
		}
		else if (u.mod == 0 && u.i == u.len)
		{
			ft_putendl("last item!!");
			u.i--;
		}
		else if (u.mod == u.i % shell->wpr)
		{
			ft_putendl(u.tmp2->name);
			ft_putendnbr("wpr IN is ", shell->wpr);
			ft_putendnbr("u.i IN is ", u.i);
			ft_putendnbr("u.mod IN is ", u.mod);
			ft_putendl("1");
			u.found = TRUE;
			if (u.tmp2->prev)
			{
				ft_putendl("2");
				u.tmp2->cursor = TRUE;
				u.tmp2 = u.tmp2->prev;
			}
			else
			{
				ft_putendl("3");
				u.found = FALSE;
				u.tmp2 = u.tmp2->prev;
			}
		}
		else
		{
			ft_putendnbr("u.i ELSE is ", u.i);
			ft_putendl(u.tmp2->name);
			ft_putendl("4");
			u.i--;
			u.tmp2 = u.tmp2->prev;
		}
	}
	ft_putendnbr("wpr AFTER is ", shell->wpr);
	ft_putendnbr("u.len AFTER is ", u.len);
	ft_putendnbr("u.i AFTER is ", u.i);
	ft_putendnbr("u.mod AFTER is ", u.mod);
	if (!u.found)
		ft_putendl("NOT FOUND!!!");
}