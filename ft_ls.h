/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 12:59:56 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/12 16:11:14 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>

typedef struct dirent		t_dir;
typedef struct stat			t_stat;

typedef struct				s_ind
{
	int						nlink;	
}							t_ind;

typedef struct				s_opt
{
	int						a;
	int						l;
	int						r1;
	int						r2;
	int						t;
}							t_opt;

typedef struct				s_ls
{
	char					*f_name;
	t_stat					st;
	struct s_ls				*next;
}							t_ls;

void						ft_error(const char *str);
void						ft_ls(t_ls *ls, t_opt opt);
t_ls						*get_name(char *dirname, t_opt opt);
int							get_dir_param(t_ls **dir, char **av, int i,
								t_opt opt);
t_ls						*new_tls(t_ls *ls);
void						alph_order(t_ls **ls, int r);
t_ls						*get_stats(t_ls *ls, t_opt opt);
void						ft_erase_lst(t_ls **ls);
void						aff_stats(t_ls *ls, t_ind ind);

#endif
