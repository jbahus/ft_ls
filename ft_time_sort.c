/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:46:55 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:32:15 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swp_time_sort(t_ls **ls, t_ls **next)
{
	t_stat		stats;
	char		*tmp;
	char		*pth;

	tmp = (*ls)->fname;
	pth = (*ls)->path;
	stats = (*ls)->st;
	(*ls)->fname = (*next)->fname;
	(*ls)->path = (*next)->path;
	(*ls)->st = (*next)->st;
	(*next)->fname = tmp;
	(*next)->st = stats;
	(*next)->path = pth;
}

void	ft_equal_sort(t_ls **next, t_ls **tmp, int r)
{
	if (r && (ft_strcmp((*tmp)->fname, (*next)->fname) < 0))
		swp_time_sort(tmp, next);
	else if (!r && (ft_strcmp((*tmp)->fname, (*next)->fname) > 0))
		swp_time_sort(next, tmp);
}

void	test(t_ls **next, t_ls **tmp, int r)
{
	if (r && ((*next)->st.st_mtimespec.tv_nsec <
		(*tmp)->st.st_mtimespec.tv_nsec))
		swp_time_sort(tmp, next);
	else if (!r && ((*next)->st.st_mtimespec.tv_nsec >
		(*tmp)->st.st_mtimespec.tv_nsec))
		swp_time_sort(tmp, next);
	else if ((*next)->st.st_mtimespec.tv_nsec ==
		(*tmp)->st.st_mtimespec.tv_nsec)
		ft_equal_sort(next, tmp, r);
}

void	ft_time_sort(t_ls **ls, int r)
{
	t_ls *tmp;
	t_ls *next;

	tmp = (*ls);
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (r && (next->st.st_mtime < tmp->st.st_mtime))
				swp_time_sort(&tmp, &next);
			else if (!r && (next->st.st_mtime > tmp->st.st_mtime))
				swp_time_sort(&tmp, &next);
			else if (next->st.st_mtime == tmp->st.st_mtime)
				test(&next, &tmp, r);
			next = next->next;
		}
		tmp = tmp->next;
	}
}
