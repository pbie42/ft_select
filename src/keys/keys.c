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

void						arrows(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
		ft_putendl("UP");
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
		ft_putendl("DOWN");
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
		ft_putendl("LEFT");
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
		ft_putendl("RIGHT");
	else if (buf[0] == 4)
	{
		printf("Ctlr+d, on quitte !\n");
		return ;
	}
}