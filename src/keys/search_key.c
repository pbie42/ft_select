/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/10/05 17:35:29 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char						*new_search(char buf)
{
	char					*search;

	search = (char *)malloc(sizeof(char) * 1 + 1);
	search[0] = buf;
	return (search);
}

char						*ft_charcat(char *s, char c)
{
	char					*dst;
	int						i;

	i = 0;
	dst = s;
	while (dst[i])
		i++;
	dst[i] = c;
	i++;
	dst[i] = '\0';
	return (s);
}

char						*add_search(char *search, char buf)
{
	char					*nw_path;
	size_t					l;

	l = ft_strlen(search) + 1;
	l += 1;
	nw_path = NULL;
	if (!(nw_path = (char*)malloc(sizeof(char) * l + 1)))
		ft_putendl("problem");
	nw_path = ft_strcpy(nw_path, search);
	nw_path = ft_charcat(nw_path, buf);
	free(search);
	return (nw_path);
}

void						search_key(t_shell *shell, char buf)
{
	t_search				s;

	s.tmp = shell->list;
	s.tmp2 = shell->list;
	s.found = FALSE;
	if (shell->search == NULL)
		shell->search = new_search(buf);
	else
		shell->search = add_search(shell->search, buf);
	s.l = ft_strlen(shell->search);
	while (s.tmp && !s.found)
	{
		if (ft_strncmp(s.tmp->name, shell->search, s.l) == 0)
			s.found = TRUE;
		else
			s.tmp = s.tmp->next;
	}
	while (s.tmp2 && s.found)
	{
		if (ft_strcmp(s.tmp->name, s.tmp2->name) == 0)
			s.tmp2->cursor = TRUE;
		else
			s.tmp2->cursor = FALSE;
		s.tmp2 = s.tmp2->next;
	}
}
