/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						shell_env_on(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->tios);
	tputs(tgetstr("vi", NULL), 1, putintc);
	tputs(tgetstr("ti", NULL), 1, putintc);
}

void						shell_env_off(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->tios_old);
	tputs(tgetstr("te", NULL), 1, putintc);
	tputs(tgetstr("ve", NULL), 1, putintc);
}