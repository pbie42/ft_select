/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_print_type(t_params *tmp)
{
	if (S_ISDIR((tmp)->st_mode))
		ft_folder_color(tmp);
	else if (S_ISLNK((tmp)->st_mode))
		ft_symlink_color(tmp);
	else if (((tmp)->st_mode > 0) && (S_IEXEC & (tmp)->st_mode))
		ft_exec_color(tmp);
	else if (S_ISREG((tmp)->st_mode))
	{
		if (tmp->cursor == TRUE)
			ft_putstr(BWHITE);
		ft_putstr((tmp)->name);
		ft_putstr(STOP);
	}
	else
		ft_putstr((tmp)->name);
}

void					ft_print_list(t_params *tmp)
{
	t_params		*tmp2;

	tmp2 = tmp;
	while (tmp2)
	{
		ft_print_type(tmp2);
		tmp2 = tmp2->next;
	}
}