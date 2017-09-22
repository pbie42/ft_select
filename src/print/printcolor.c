/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:23:16 by pbie              #+#    #+#             */
/*   Updated: 2016/05/18 17:15:42 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_folder_color(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		ft_putstr(BCYAN);
	if (tmp->selected == TRUE)
		ft_putstr(INVCYAN);
	else
		ft_putstr(CYAN);
	ft_putstr(tmp->name);
	ft_putstr(STOP);
}

void			ft_exec_color(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		ft_putstr(BRED);
	if (tmp->selected == TRUE)
		ft_putstr(INVRED);
	else
		ft_putstr(RED);
	ft_putstr(tmp->name);
	ft_putstr(STOP);
}

void			ft_symlink_color(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		ft_putstr(BMAGENTA);
	if (tmp->selected == TRUE)
		ft_putstr(INVMAGENTA);
	else
		ft_putstr(MAGENTA);
	ft_putstr(tmp->name);
	ft_putstr(STOP);
}
