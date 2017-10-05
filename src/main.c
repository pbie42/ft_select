/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 15:16:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						interrogate(t_caps *c)
{
	c->cl_string = tgetstr("cl", 0);
	c->cm_string = tgetstr("cm", 0);
	c->auto_wrap = tgetflag("am");
	c->height = tgetnum("li");
	c->width = tgetnum("co");
	c->temp = tgetstr("pc", 0);
	c->pc = c->temp ? *c->temp : 0;
	c->bc = tgetstr("le", 0);
	c->up = tgetstr("up", 0);
}

int							loop(char **av)
{
	t_shell					*shell;
	char					buf[4];
	t_caps					c;

	interrogate(&c);
	shell = get_shell();
	updateshell(shell);
	shell->list = set_params(av, ".");
	shell->list->cursor = TRUE;
	ft_signal();
	while (1)
	{
		tputs(c.cl_string, 1, putintc);
		keys(buf, shell);
		view(shell);
		bzero(buf, 4);
		read(0, buf, 4);
		updateshell(shell);
	}
	return (0);
}

int							main(int ac, char **av, char **ev)
{
	char					*term_type;
	int						success;

	(void)ac;
	(void)ev;
	// if (isatty(0))
	// 	ft_putstr_fd("the standard input is from a terminal\n", 0);
	// else
	// 	ft_putstr_fd("the standard input is NOT from a terminal\n", 0);
	// if (isatty(1))
	// 	ft_putstr_fd("the standard output is to a terminal\n", 0);
	// else
	// 	ft_putstr_fd("the standard input is NOT to a terminal\n", 0);
	// // exit(0);
	if (!av[1])
		ft_exit("Please enter at least one argument");
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
	loop(av);
	return (0);
}
