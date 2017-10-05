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

void			ft_cursor_color(void)
{
	ft_putstr_fd("[", 0);
	ft_putstr_fd(BGREEN, 0);
	ft_putstr_fd("⪢", 0);
	ft_putstr_fd(STOP, 0);
}

void			ft_folder_color(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		ft_putstr_fd(BCYAN, 0);
	if (tmp->selected == TRUE)
		ft_putstr_fd(INVCYAN, 0);
	else
		ft_putstr_fd(CYAN, 0);
	ft_putstr_fd(tmp->name, 0);
	ft_putstr_fd(STOP, 0);
}

void			ft_exec_color(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		ft_putstr_fd(BRED, 0);
	if (tmp->selected == TRUE)
		ft_putstr_fd(INVRED, 0);
	else
		ft_putstr_fd(RED, 0);
	ft_putstr_fd(tmp->name, 0);
	ft_putstr_fd(STOP, 0);
}

void			ft_symlink_color(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		ft_putstr_fd(BMAGENTA, 0);
	if (tmp->selected == TRUE)
		ft_putstr_fd(INVMAGENTA, 0);
	else
		ft_putstr_fd(MAGENTA, 0);
	ft_putstr_fd(tmp->name, 0);
	ft_putstr_fd(STOP, 0);
}
