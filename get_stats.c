/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:15:39 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/12 16:10:53 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swp_time_order(t_ls **ls, t_ls **next)
{
	t_stat		stats;
	char		*tmp;

	tmp = (*ls)->f_name;
	stats = (*ls)->st;
	(*ls)->f_name = (*next)->f_name;
	(*ls)->st = (*next)->st;
	(*next)->f_name = tmp;
	(*next)->st = stats;
}

/*t_tls	*get_isdir(t_tls *tls)
{
	t_stat	*st;
	t_tls	*tmp;

	tmp = tls;
	st = malloc(sizeof(*st));
	while (tmp->next)
	{
		stat(tmp->f_name, st);
		tmp->isdir = S_ISDIR(st->st_mode);
		tmp = tmp->next;
	}
	return (tls);
}*/

void	trie_time(t_ls **ls, t_opt opt)
{
	t_ls *tmp;
	t_ls *next;

	tmp = (*ls);
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (opt.r1)
			{
				if (next->st.st_mtime < tmp->st.st_mtime)
					swp_time_order(&tmp, &next);
			}
			else if (next->st.st_mtime > tmp->st.st_mtime)
				swp_time_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

t_ls	*get_stats(t_ls *ls, t_opt opt)
{
	t_ls	*tmp;
	int		ret;

	tmp = ls;
	while (tmp)
	{
		if ((ret = stat(tmp->f_name, &tmp->st)) == -1)
			ft_error(tmp->f_name);
		tmp = tmp->next;
	}
	if (opt.t)
		trie_time(&ls, opt);
	return (ls);
}