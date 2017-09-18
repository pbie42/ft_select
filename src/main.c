/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/15 11:37:47 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						interrogate(t_caps *c)
{
#ifdef Unix

	char *buffer = (char *)malloc(strlen(term_buffer));
# define BUFFADDR &buffer
#else
# define BUFFADDR 0

#endif

	c->cl_string = tgetstr("cl", BUFFADDR);
	c->cm_string = tgetstr("cm", BUFFADDR);
	c->auto_wrap = tgetflag("am");
	c->height = tgetnum("li");
	c->width = tgetnum("co");
	c->temp = tgetstr("pc", BUFFADDR);
	c->pc = c->temp ? *c->temp : 0;
	c->bc = tgetstr("le", BUFFADDR);
	c->up = tgetstr("up", BUFFADDR);
	ft_putendl("end of interrogate");
}

/*
** inputs an arbitrary int into
** the stdin
*/

int							putintc(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

int							which_key(t_caps c)
{
	t_shell				*shell;
	char					buffer[4];

	new_shell(&shell);
	while (1)
	{
		tputs(c.cl_string, 1, putintc);
		read(0, buffer, 3);
		if (buffer[0] == 27)
		{
			printf("C'est une fleche !\n");
			printf("HOLLA! !\n");
		}
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}

int							main(int ac, char **av, char **ev)
{
	char					*term_type;
	struct termios			term;
	int						success;
	int						argc;
	char					**argv;
	char					**envv;
	t_caps				c;

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
	if (tcgetattr(0, &term) == -1)
		return (-1);
	interrogate(&c);
	which_key(c);
	return (0);
}
