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

void						arrows(char *buf, t_shell *shell)
{
	t_shell				*shell2;

	shell2 = shell;
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
		ft_putendl("UP");
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
		arrow_down(shell);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
		arrow_left(shell);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
		arrow_right(shell);
	else if (buf[0] == 4)
	{
		printf("Ctlr+d, on quitte !\n");
		return ;
	}
}

void						keys(char *buf, t_shell *shell)
{
	if (buf[0] == 27)
		arrows(buf, shell);
}