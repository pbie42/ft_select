/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						keys(char *buf, t_shell *shell)
{
	if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		handle_exit(1);
	if (buf[0] == 27)
		arrows(buf, shell);
	if (buf[0] == 10 )
		enter_key(shell);
	if (buf[0] == 32)
		space_key(shell);
	if (buf[0] == 126)
		delete_key(shell);
	if (buf[0] == 127)
		delete_key(shell);
	else
	{
		// ft_putendnbr("buf[0] = ", buf[0]);
	}
}