/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 12:18:27 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 14:44:01 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		swp_ascii_sort(t_ls **tmp, t_ls **next)
{
	char	*name;
	char	*path;
	t_stat	st;

	name = (*next)->fname;
	(*next)->fname = (*tmp)->fname;
	(*tmp)->fname = name;
	st = (*next)->st;
	(*next)->st = (*tmp)->st;
	(*tmp)->st = st;
	path = (*next)->path;
	(*next)->path = (*tmp)->path;
	(*tmp)->path = path;
}

void			ft_ascii_sort(t_ls **lst, int r)
{
	t_ls *tmp;
	t_ls *next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (r && (ft_strcmp(tmp->fname, next->fname) < 0))
				swp_ascii_sort(&tmp, &next);
			else if (!r && (ft_strcmp(tmp->fname, next->fname) > 0))
				swp_ascii_sort(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
}
