/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 15:03:19 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_put_padding(char *name, int max)
{
	size_t				i;
	size_t				diff;

	i = -1;
	diff = max - ft_strlen(name);
	while (++i < diff)
		ft_putchar(' ');
}

void					view_print(t_params *tmp, t_shell *shell)
{
	if (tmp->cursor == TRUE)
		ft_cursor_color();
	else
		ft_putstr("[ ");
	ft_print_type(tmp);
	ft_put_padding(tmp->name, shell->sizemax);
	ft_putstr(" ]");
}

void					view(t_shell *shell)
{
	t_params			*tmp;
	t_params			*del;
	int					i;

	get_max(shell);
	words_per_row(shell);
	tmp = shell->list;
	i = 1;
	if (shell->deleted)
	{
		del = shell->deleted;
		while (del)
			del = del->d_next;
	}
	while (tmp)
	{
		view_print(tmp, shell);
		if (i % shell->wpr == 0)
			ft_putchar('\n');
		i++;
		tmp = tmp->next;
	}
}
