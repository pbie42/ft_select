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

void					ft_print_norm(t_params *tmp)
{
	if (tmp->selected == TRUE)
		ft_putstr_fd(INVWHITE, 0);
	if (tmp->cursor == TRUE)
		ft_putstr_fd(BWHITE, 0);
	ft_putstr_fd((tmp)->name, 0);
	ft_putstr_fd(STOP, 0);
}

void					ft_print_type(t_params *tmp)
{
	if (tmp->cursor == TRUE)
		tputs(tgetstr("us", NULL), 1, putintc);
	if ((tmp)->st_mode && S_ISDIR((tmp)->st_mode))
		ft_folder_color(tmp);
	else if ((tmp)->st_mode && S_ISLNK((tmp)->st_mode))
		ft_symlink_color(tmp);
	else if ((tmp)->st_mode && ((tmp)->st_mode > 0)
				&& (S_IEXEC & (tmp)->st_mode))
		ft_exec_color(tmp);
	else if ((tmp)->st_mode && S_ISREG((tmp)->st_mode))
		ft_print_norm(tmp);
	else
		ft_print_norm(tmp);
}

void					ft_print_list(t_params *tmp)
{
	t_params		*tmp2;

	tmp2 = tmp;
	while (tmp2)
	{
		ft_print_type(tmp2);
		if (tmp2->cursor == TRUE)
			tputs(tgetstr("ue", NULL), 1, putintc);
		tmp2 = tmp2->next;
	}
}
