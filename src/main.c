/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						which_key(void)
{
	char					buffer[3];

	while(1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
		  printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
		  printf("Ctlr+d, on quitte !\n");
		  return (0);
		}
	}
	return (0);
}

int						main(int ac, char **av, char **ev)
{
	char					*term_type;
	struct termios		term;
	int					success;
	int					argc;
	char					**argv;
	char					**envv;

	argc = ac;
	argv = av;
	envv = ev;
	if ((term_type = getenv("TERM")) == NULL)
		return (-1);
	if (term_type == 0)
		ft_exit("Specify a terminal type with `setenv TERM <yourtype>'.\n");
	if ((success = tgetent(NULL, term_type)) < 0)
		ft_exit("Could not access the termcap data base.\n");
	if (success == 0)
	{
		ft_putstr("Terminal type ");
		ft_putstr(term_type);
		ft_exit(" is not defined.\n");
	}
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
		return (-1);
	which_key();
	return (0);
}