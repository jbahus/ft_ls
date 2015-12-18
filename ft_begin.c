/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:41:37 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 15:01:45 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*check_opt_file(t_dir *file, t_ls *lst, char *str)
{
	char	*tmp;

	lst = new_lst(lst);
	lst->fname = ft_strdup(file->d_name);
	tmp = ft_strjoin(str, "/");
	lst->path = ft_strjoin(tmp, lst->fname);
	free(tmp);
	return (lst);
}

t_ls	*get_files(char *str, t_opt opt)
{
	DIR		*dir;
	t_dir	*file;
	t_ls	*lst;

	lst = NULL;
	if ((dir = opendir(str)))
	{
		while ((file = readdir(dir)))
		{
			if ((!opt.a && file->d_name[0] != '.') || opt.a)
				lst = check_opt_file(file, lst, str);
		}
		closedir(dir);
	}
	else
		ft_error(str, 0);
	if (!opt.t)
		ft_ascii_sort(&lst, opt.r1);
	else
		ft_time_sort(&lst, opt.r1);
	return (lst);
}

void	ft_do(char *str, t_opt opt, int ind, int i)
{
	t_ls	*lst;

	if (ind || i)
	{
		ft_putstr(str);
		ft_putendl(":");
	}
	lst = get_files(str, opt);
	if (opt.t == 1 || opt.r2 == 1 || opt.l == 1)
		lst = get_stats(lst, opt);
	lst = ft_ls(lst, opt);
	while (lst)
	{
		ft_putchar('\n');
		ft_do(lst->fname, opt, 0, 1);
		lst = ft_lst_del(lst);
	}
	if (ind == 1)
		ft_putchar('\n');
}
