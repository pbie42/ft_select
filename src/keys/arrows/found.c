/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						found_up(t_up *u, t_params *tmp)
{
	u->found = TRUE;
	tmp->cursor = TRUE;
}

void						found_down(t_down *d)
{
	d->found = TRUE;
	d->tmp2->cursor = TRUE;
}
