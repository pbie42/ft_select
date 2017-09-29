/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcolor_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_folder_color_out(t_params *tmp)
{
	ft_putstr_fd(CYAN, 1);
	ft_putstr_fd(tmp->name, 1);
	ft_putstr_fd(STOP, 1);
}

void			ft_exec_color_out(t_params *tmp)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(tmp->name, 1);
	ft_putstr_fd(STOP, 1);
}

void			ft_symlink_color_out(t_params *tmp)
{
	ft_putstr_fd(MAGENTA, 1);
	ft_putstr_fd(tmp->name, 1);
	ft_putstr_fd(STOP, 1);
}
