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
		// ft_putendl("1");
		mod = i++ % shell->wpr;
		tmp = tmp->next;
	}
	// ft_putstr("wpr is ");
	// ft_putnbr(shell->wpr);
	// ft_putchar('\n');
	// ft_putstr("i is ");
	// ft_putnbr(i);
	// ft_putchar('\n');
	// ft_putstr("mod is ");
	// ft_putnbr(mod);
	// ft_putchar('\n');
	tmp->cursor = FALSE;
	found = FALSE;
	while (tmp && !found)
	{
		if (mod == 0 && i == 0)
		{
			// ft_putendl("1");
			i++;
		}
		else if (mod == i++ % shell->wpr && i != 0)
		{
			// ft_putendl("2");
			found = TRUE;
			tmp = tmp->next;
			tmp->cursor = TRUE;
		}
		else
		{
			// ft_putendl("3");
			tmp = tmp->next;
		}
	}
	// ft_putstr("i after is ");
	// ft_putnbr(i);
	// ft_putchar('\n');
	// ft_putstr("mod after is ");
	// ft_putnbr(mod);
	// ft_putchar('\n');
	tmp2 = shell->list;
	i = 0;
	if (tmp == NULL && !found)
	{
		// ft_putendl("last if");
		while (tmp2 && !found)
		{
			if (ft_strcmp(tmp2->name, shell->list->name) == 0)
			{
				// ft_putendl("here fool!!!");
				// ft_putstr("i fool is ");
				// ft_putnbr(i);
				// ft_putchar('\n');
				// ft_putstr("mod fool is ");
				// ft_putnbr(mod);
				// ft_putchar('\n');
				if (i == 0 && mod == shell->wpr - 1 % shell->wpr)
				{
					found = TRUE;
					tmp2->cursor = TRUE;
				}
			}
			if (mod == i++ % shell->wpr)
			{
				// ft_putendl("4");
				found = TRUE;
				tmp2 = tmp2->next;
				tmp2->cursor = TRUE;
			}
			else
			{
				// ft_putendl("5");
				tmp2 = tmp2->next;
			}
		}
	}
	if (found == FALSE)
		ft_putendl("not found");
	// ft_putendl("end");
}