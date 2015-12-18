/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:46:18 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:38:58 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls			*aff_link_get_dir(t_ls *ls, t_opt opt, t_ls *dir)
{
	char	*str;

	str = NULL;
	if (opt.l && S_ISLNK(ls->st.st_mode))
	{
		str = malloc(sizeof(char) * 2000);
		if (readlink(ls->path, str, 2000) > 0)
		{
			ft_putstr(" -> ");
			ft_putstr(str);
			ft_bzero(str, ft_strlen(str));
		}
		free(str);
	}
	if ((opt.a && S_ISDIR(ls->st.st_mode) && opt.r2 &&
		ft_strncmp(ls->fname, ".", ft_strlen(ls->fname)) &&
		ft_strncmp(ls->fname, "..", ft_strlen(ls->fname)))
		|| (opt.r2 && !opt.a && ls->fname[0] != '.'
		&& S_ISDIR(ls->st.st_mode)))
	{
		dir = new_lst(dir);
		dir->fname = ft_strdup(ls->path);
	}
	return (dir);
}

t_ls			*ft_aff_files(t_ls *ls, t_opt opt, t_ls *dir, t_ind ind)
{
	char	*str;

	while (ls)
	{
		str = ls->fname;
		if ((str[0] != '.' && !opt.a) || opt.a)
		{
			if (opt.l)
				aff_stats(ls, ind);
			ft_putstr(ls->fname);
			if (opt.l || opt.r2)
				dir = aff_link_get_dir(ls, opt, dir);
			ft_putchar('\n');
		}
		ls = ft_lst_del(ls);
	}
	return (dir);
}

t_ls			*ft_ls(t_ls *ls, t_opt opt)
{
	t_ind	ind;
	t_ls	*dir;

	dir = NULL;
	if (opt.l && !ls)
		check_stats(ls, &ind, opt, 0);
	else if (opt.l)
		check_stats(ls, &ind, opt, 1);
	dir = ft_aff_files(ls, opt, dir, ind);
	if (opt.t)
		ft_time_sort(&dir, opt.r1);
	else
		ft_ascii_sort(&dir, opt.r1);
	return (dir);
}
