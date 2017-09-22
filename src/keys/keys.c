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
	if (buf[0] == 27)
		arrows(buf, shell);
	if (buf[0] == 10 )
		enter_key(shell);
	if (buf[0] == 32)
		space_key(shell);
	if (buf[0] == 127)
		delete_key(shell);
	else
	{
		// ft_putendnbr("buf i ", buf[0]);
	}
}