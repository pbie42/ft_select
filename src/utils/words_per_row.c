/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_per_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						words_per_row(t_shell *shell)
{
	int					new_max;
	int					wpr;

	new_max = shell->sizemax + 4;
	wpr = shell->wsz.ws_col / new_max;
	ft_putstr("ws_row: ");
	printf("wpr ws_row: %d\n", shell->wsz.ws_col);
	ft_putstr("wpr: ");
	ft_putnbr(wpr);
	ft_putchar('\n');
	return (wpr);
}