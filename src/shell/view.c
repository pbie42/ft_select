/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_put_padding(char *name, int max)
{
	size_t				i;
	size_t				diff;

	i = -1;
	diff = max - ft_strlen(name);
	while (++i < diff)
		ft_putchar(' ');
}

void						view(t_shell *shell)
{
	t_params				*tmp;
	int					wpr;
	int					i;

	get_max(shell);
	wpr = words_per_row(shell);
	tmp = shell->list;
	i = 0;
	while (tmp)
	{
		if (tmp->cursor == TRUE)
		{
			ft_putstr("[");
			ft_putstr(BGREEN);
			ft_putstr("⪢");
			ft_putstr(STOP);
		}
		else
			ft_putstr("[ ");
		ft_print_type(tmp);
		ft_put_padding(tmp->name, shell->sizemax);
		ft_putstr(" ]");
		if (i != 0 && i % wpr == 0)
			ft_putchar('\n');
		tmp = tmp->next;
	}
}