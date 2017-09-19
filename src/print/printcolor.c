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

void			ft_folder_color(char *ptr)
{
	ft_putstr(CYAN);
	ft_putstr(ptr);
	ft_putstr(STOP);
	ft_putchar('\n');
}

void			ft_exec_color(char *ptr)
{
	ft_putstr(RED);
	ft_putstr(ptr);
	ft_putstr(STOP);
	ft_putchar('\n');
}

void			ft_symlink_color(char *ptr)
{
	ft_putstr(MAGENTA);
	ft_putstr(ptr);
	ft_putstr(STOP);
	ft_putchar('\n');
}
