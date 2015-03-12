/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:23:29 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/12 16:14:47 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swp_alph_order(t_ls **tmp, t_ls **next)
{
	char	*yolo;

	yolo = (*next)->f_name;
	(*next)->f_name = (*tmp)->f_name;
	(*tmp)->f_name = yolo;
}

void	alph_order(t_ls **ls, int r)
{
	t_ls *tmp;
	t_ls *next;

	tmp = *ls;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (r)
			{
				if (ft_strcmp(tmp->f_name, next->f_name) < 0)
					swp_alph_order(&tmp, &next);
			}
			else if (ft_strcmp(tmp->f_name, next->f_name) > 0)
				swp_alph_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

t_ls	*new_tls(t_ls *ls)
{
	t_ls	*new_t;

	new_t = (t_ls*)malloc(sizeof(t_ls));
	new_t->next = ls;
	return (new_t);
}

t_ls	*get_name(char *dirname, t_opt opt)
{
	DIR		*dir;
	t_dir	*files;
	t_ls	*ls;

	if (dirname == NULL)
	{
		if (!(dir = opendir("./")))
			ft_error("./");
	}
	else if (!(dir = opendir(dirname)))
		ft_error(dirname);
	ls = NULL;
	while ((files = readdir(dir)))
	{
		ls = new_tls(ls);
		if (dirname)
			ls->f_name = ft_strjoin(dirname, files->d_name);
		else
			ls->f_name = files->d_name;
	}
	free(files);
	alph_order(&ls, opt.r1);
	closedir(dir);
	return (ls);
}
