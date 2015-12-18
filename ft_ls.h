/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:22:38 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:57:42 by jbahus           ###   ########.fr       */
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
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct passwd	t_uid;
typedef struct group	t_grp;
typedef struct tm		t_time;

typedef struct			s_ind
{
	int					nlink;
	size_t				uid;
	size_t				grp;
	off_t				bytes;
	size_t				major;
	size_t				minor;
}						t_ind;

typedef struct			s_opt
{
	int					a;
	int					l;
	int					r1;
	int					r2;
	int					t;
}						t_opt;

typedef struct			s_error
{
	char				*name;
	int					msg;
	struct s_error		*next;
}						t_error;

typedef struct			s_ls
{
	char				*fname;
	char				*path;
	t_stat				st;
	struct s_ls			*next;
}						t_ls;

t_opt					do_opt(t_opt opt, char **av, int *i);
t_ls					*new_lst(t_ls *ls);
void					ft_do(char *str, t_opt opt, int ind, int i);
void					ft_error(const char *str, int str_errno);
void					ft_ind();
void					ft_write_error(t_error *error, t_opt opt);
void					ft_write_files(t_ls *lst, t_opt opt, t_ls *path);
void					ft_ascii_sort(t_ls **lst, int r);
t_ls					*ft_lst_del(t_ls *lst);
void					ft_time_sort(t_ls **ls, int r);
t_ls					*get_stats(t_ls *lst, t_opt opt);
void					check_stats(t_ls *ls, t_ind *ind, t_opt opt, int ok);
t_ls					*ft_ls(t_ls *ls, t_opt opt);
void					aff_stats(t_ls *ls, t_ind ind);
void					aff_uid_grp(t_ls *ls, t_ind ind);
void					aff_min_maj(t_stat buff, t_ind ind);
void					ft_ind_init(t_ind *ind);
void					ft_check_min_maj(t_stat buff, t_ind *ind);
void					ft_space_device(t_ind ind);
int						little_check(char *str, t_opt opt);
int						ft_little_date(char *date, int i, time_t ls_mtime);
void					ft_ind_stuff(t_ls *ls, t_ind *ind, t_uid *uid);
void					ft_main_do(t_ls *path, t_opt opt, int i, int j);

#endif
