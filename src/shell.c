/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				new_shell(t_shell *shell)
{
	shell = (t_shell *)malloc(sizeof(t_shell))
	shell->list = NULL;
	shell->tios_old = (struct termios*)malloc(sizeof(struct termios));
	shell->tios = (struct termios*)malloc(sizeof(struct termios));
}