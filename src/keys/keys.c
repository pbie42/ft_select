/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 14:32:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						keys(char *buf, t_shell *shell)
{
	// ft_putendnbr("buf[0] = ", buf[0]);
	// ft_putendnbr("buf[1] = ", buf[1]);
	// ft_putendnbr("buf[2] = ", buf[2]);
	// ft_putendnbr("buf[3] = ", buf[3]);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 72 && buf[3] == 0)
		select_key(shell);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 70 && buf[3] == 0)
		deselect_key(shell);
	if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		handle_exit(1);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
		delete_key(shell);
	else if (buf[0] == 127 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		delete_key(shell);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 53 && buf[3] == 126)
		undo_key(shell);
	else if (buf[0] == 27)
		arrows(buf, shell);
	else if (buf[0] == 10)
		enter_key(shell);
	else if (buf[0] == 32)
		space_key(shell);
	else if (ft_isalnum(buf[0]))
		search_key(shell, buf[0]);
}
