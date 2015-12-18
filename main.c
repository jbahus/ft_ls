/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:20:32 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:57:31 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	ft_init(t_opt opt)
{
	opt.r1 = 0;
	opt.r2 = 0;
	opt.t = 0;
	opt.a = 0;
	opt.l = 0;
	return (opt);
}

t_error	*ft_get_error(t_error *error, char *str)
{
	t_error	*new_error;

	new_error = (t_error*)malloc(sizeof(t_error));
	new_error->name = ft_strdup(str);
	new_error->msg = errno;
	new_error->next = error;
	return (new_error);
}

void	ft_stuff(t_error **error, t_ls **lst, t_ls **path, char *arg)
{
	int		ret;
	t_stat	st;

	ret = 0;
	ret = lstat(arg, &st);
	if (errno == EACCES && S_ISDIR(st.st_mode))
	{
		(*path) = new_lst(*path);
		(*path)->fname = ft_strdup(arg);
		(*path)->path = ft_strdup(arg);
		return ;
	}
	if ((errno == ENOTDIR) || (ret >= 0))
	{
		(*lst) = new_lst(*lst);
		(*lst)->fname = ft_strdup(arg);
		if ((ret = lstat((*lst)->fname, &(*lst)->st)) == -1)
			ft_error((*lst)->fname, 0);
		(ret == -1) ? ((*lst) = ft_lst_del((*lst))) : 0;
		return ;
	}
	if (errno == ENOENT)
		*error = ft_get_error(*error, arg);
}

t_ls	*ft_get_path(int i, char **av, t_ls *path, t_opt opt)
{
	DIR		*dir;
	t_error	*error;
	t_ls	*lst;

	error = NULL;
	lst = NULL;
	while (av[i])
	{
		if ((dir = opendir(av[i])) && !little_check(av[i], opt))
		{
			path = new_lst(path);
			path->fname = ft_strdup(av[i]);
			path->path = ft_strdup(av[i++]);
			closedir(dir);
		}
		else
			ft_stuff(&error, &lst, &path, av[i++]);
	}
	ft_write_error(error, opt);
	ft_write_files(lst, opt, path);
	if (opt.t)
		path = get_stats(path, opt);
	else
		ft_ascii_sort(&path, opt.r1);
	return (path);
}

int		main(int ac, char **av)
{
	int		i;
	t_opt	opt;
	t_ls	*path;
	int		j;

	i = 1;
	path = NULL;
	opt = ft_init(opt);
	opt = do_opt(opt, av, &i);
	if (av[i])
	{
		j = ac - i;
		path = ft_get_path(i, av, path, opt);
		i = 0;
		ft_main_do(path, opt, i, j);
	}
	else
		ft_do(".", opt, 0, 0);
	return (0);
}
