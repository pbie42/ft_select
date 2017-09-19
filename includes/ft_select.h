/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/09/10 14:53:52 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define TRUE 1
# define FALSE 0
# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGLIGHT "\033[47m"
# define BGGRAY "\033[47m"

# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <ftw.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <termios.h>
# include <err.h>
# include <termcap.h>
# include "../libft/includes/libft.h"
# include <term.h>

typedef int					t_bool;

typedef struct		s_params
{
	char			*name;
	t_bool				selected;
	t_bool				cursor;
	mode_t			st_mode;
	struct s_params	*next;
	struct s_params	*prev;
}					t_params;

typedef struct		s_shell
{
	struct winsize	wsz;
	t_params		*list;
	struct termios	*tios_old;
	struct termios	*tios;
	int				sizemax;
	int				wbl;
}					t_shell;

typedef struct				s_caps
{
	int						height;
	int						width;
	int						auto_wrap;
	char					*cl_string;
	char					*cm_string;
	char					pc;
	char					*bc;
	char					*up;
	char					*temp;
}								t_caps;

typedef struct				s_lists
{
	t_params					*list;
	t_params					*tmp;
	t_params					*tmp2;
}							t_lists;

typedef struct		s_single
{
	t_params			*alist;
	struct stat		fstat;
	char			*nw_path;
}					t_single;

t_params				*set_params(char **av, char *pwd);
char						*make_path_fl(char *dir, char *file);
void						ft_folder_color(char *ptr);
void						ft_exec_color(char *ptr);
void						ft_symlink_color(char *ptr);
void						new_shell(t_shell *shell);
void						arrows(char *buf);
void						ft_print_list(t_params *tmp);
void						updateshell(t_shell *shell);
int							putintc(int c);

#endif //FT_SELECT_H
