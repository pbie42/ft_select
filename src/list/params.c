/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/09/29 14:55:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_params				*invalid_single(char *name)
{
	t_single			s;

	if (!(s.alist = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	s.alist->name = ft_strdup(name);
	s.alist->cursor = FALSE;
	s.alist->selected = FALSE;
	s.alist->deleted = FALSE;
	s.alist->next = NULL;
	s.alist->prev = NULL;
	return (s.alist);
}

t_params				*list_single(char *name, char *pwd)
{
	t_single			s;

	s.nw_path = make_path_fl(pwd, name);
	if (lstat(s.nw_path, &s.fstat) < 0)
	{
		free(s.nw_path);
		ft_putendl("invalid");
		return (invalid_single(name));
	}
	free(s.nw_path);
	if (!(s.alist = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	s.alist->st_mode = s.fstat.st_mode;
	s.alist->name = ft_strdup(name);
	s.alist->cursor = FALSE;
	s.alist->selected = FALSE;
	s.alist->prev = NULL;
	return (s.alist);
}

t_params				*set_params(char **av, char *pwd)
{
	t_lists				l;
	int					i;

	i = 1;
	if (av[i] != NULL)
	{
		l.list = list_single(av[i++], pwd);
		l.list->prev = NULL;
	}
	else
		return (NULL);
	l.tmp = l.list;
	while (av[i] != NULL)
	{
		l.tmp2 = list_single(av[i], pwd);
		if (l.tmp2 != NULL)
		{
			l.list->next = l.tmp2;
			l.tmp2->prev = l.list;
			l.list = l.list->next;
		}
		i++;
	}
	return (l.tmp);
}
