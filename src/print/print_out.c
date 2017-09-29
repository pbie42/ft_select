/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_print_type_out(t_params *tmp)
{
	if (S_ISDIR((tmp)->st_mode))
		ft_folder_color_out(tmp);
	else if (S_ISLNK((tmp)->st_mode))
		ft_symlink_color_out(tmp);
	else if (((tmp)->st_mode > 0) && (S_IEXEC & (tmp)->st_mode))
		ft_exec_color_out(tmp);
	else if (S_ISREG((tmp)->st_mode))
	{
		ft_putstr_fd((tmp)->name, 1);
		ft_putstr_fd(STOP, 1);
	}
	else
		ft_putstr_fd((tmp)->name, 1);
}
